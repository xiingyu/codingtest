//  산타의 선물 공장 2
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define _MAX_M (100000)

#define _QUERY_INIT                (100)
#define _QUERY_MOVE_ALL            (200)
#define _QUERY_EXCHANGE            (300)
#define _QUERY_DIVIDE            (400)
#define _QUERY_INFO_PRESENT        (500)
#define _QUERY_INFO_BELT        (600)

extern void Init(int N, int M, int* list_pos);
extern int Move_All(int m_src, int m_dst);
extern int Exchange(int m_src, int m_dst);
extern int Divide(int m_src, int m_dst);
extern int Get_Info_By_Present(int p_num);
extern int Get_Info_By_Belt(int b_num);

int pos_gift[_MAX_M + 1];

int main(void) {
    //freopen("santa_02.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    int n, m;
    int m_src, m_dst, b_num, p_num, ret;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int type_q;
        cin >> type_q;
        switch (type_q) {
        case _QUERY_INIT:
            cin >> n >> m;
            for (int i = 1; i <= m; i++) cin >> pos_gift[i];
            Init(n, m, pos_gift);
            break;
        case _QUERY_MOVE_ALL:
            cin >> m_src >> m_dst;
            ret = Move_All(m_src, m_dst);
            cout << ret << '\n';
            break;
        case _QUERY_EXCHANGE:
            cin >> m_src >> m_dst;
            ret = Exchange(m_src, m_dst);
            cout << ret << '\n';
            break;
        case _QUERY_DIVIDE:
            cin >> m_src >> m_dst;
            ret = Divide(m_src, m_dst);
            cout << ret << '\n';
            break;
        case _QUERY_INFO_PRESENT:
            cin >> p_num;
            ret = Get_Info_By_Present(p_num);
            cout << ret << '\n';
            break;
        case _QUERY_INFO_BELT:
            cin >> b_num;
            ret = Get_Info_By_Belt(b_num);
            cout << ret << '\n';
            break;
        }
    }
    return 0;
}

#define MAX_M (100000)
#define MAX_N (100000)

struct NODE {
    int no_present;
    NODE* prev;
    NODE* next;
};

struct LIST {
    NODE head, tail;
    int cnt;

    void splice_list(LIST& l) {
        // list l의 모든 노드를 이 리스트의 제일 앞쪽에 추가하기
        if (l.cnt == 0) return;

        NODE& p_insert = head;
        NODE& n_insert = *(head.next);

        NODE* first = l.head.next;
        NODE* last = l.tail.prev;

        p_insert.next = first;
        first->prev = &p_insert;

        last->next = &n_insert;
        n_insert.prev = last;

        cnt += l.cnt;
        l.init();
    }

    void get_range_from_head(NODE*& first, NODE*& last, int n) {
        first = head.next;    // list 첫 노드의 주소
        last = head.next;    // 탐색 위해 첫 노드 주소부터 시작
        cnt -= n;            // list에서 떼어낼 노드 수 차람
        n--;
        while (n--) {        // n만큼 뒷 노드 찾아가기..
            last = last->next;
        }

        // first~last 구간 떼어내기
        first->prev->next = last->next;
        last->next->prev = first->prev;
    }

    void splice_range(NODE* first, NODE* last, int cnt_move) {
        cnt += cnt_move;                    // first~last 까지 연결된 노드를 현재 리스트 제일 앞쪽에 끼워넣기

        NODE& p_insert = head;                // 끼워놓을 위치의 앞쪽 노드
        NODE& n_insert = *(head.next);        // 끼워놓을 위치의 뒤쪽 노드

        p_insert.next = first;                // 앞쪽 노드 <-> first 연결
        first->prev = &p_insert;

        last->next = &n_insert;                // last <-> 뒤쪽 노드 연결
        n_insert.prev = last;
    }

    void push_back(NODE* newnode) {
        // newnode를 list 제일 뒤에 추가
        cnt++;
        newnode->next = &tail;
        newnode->prev = tail.prev;

        newnode->prev->next = newnode;
        newnode->next->prev = newnode;

    }
    void push_front(NODE* newnode) {
        // newnode를 list 제일 앞에 추가
        cnt++;
        newnode->next = head.next;
        newnode->prev = &head;

        newnode->prev->next = newnode;
        newnode->next->prev = newnode;
    }

    NODE* Get_First(void) {
        // list의 제일 앞 노드를 list에서 끊고 노드 주소 리턴
        if (cnt == 0) return (NODE*)0;
        cnt--;
        NODE* ret = head.next;

        ret->prev->next = ret->next;
        ret->next->prev = ret->prev;

        return ret;
    }

    void init(void) {
        // list 초기화
        cnt = 0;
        head.next = &tail;
        tail.prev = &head;
    }
};

NODE alloc[MAX_N]; // 노드 필요 시 사용
int idx_alloc;
LIST belts[MAX_N + 1];
NODE* p_present[MAX_N + 1];

NODE* Alloc(void) {
    // Node 동적 할당 대신 배열에서 하나씩 떼어다가 사용
    return &alloc[idx_alloc++];
}

void Init_List(int N) {
    idx_alloc = 0;
    for (int n = 1; n <= N; n++) {
        belts[n].init();
    }
}

void Init(int N, int M, int* list_pos) {
    // 전체 초기화
    // O(N+M) : 한번 호출되고 끝
    Init_List(N);                                // 벨트 초기화
    for (int i = 1; i <= M; i++) {                // 선물 정보 벨트에 추가
        NODE* newnode = Alloc();
        newnode->no_present = i;
        belts[list_pos[i]].push_back(newnode);
        p_present[i] = newnode;
    }
}

int Move_All(int m_src, int m_dst) {
    // m_src 벨트에 있는 것 m_dst 벨트에 모두 옮기기 : O(1)
    belts[m_dst].splice_list(belts[m_src]);
    return belts[m_dst].cnt;
}

int Exchange(int m_src, int m_dst) {
    // m_src, m_dst 에 있는 것 서로 바꾸기 : O(1)
    NODE* node_src = belts[m_src].Get_First();
    NODE* node_dst = belts[m_dst].Get_First();

    if (node_src) belts[m_dst].push_front(node_src);
    if (node_dst) belts[m_src].push_front(node_dst);

    return belts[m_dst].cnt;
}

int Divide(int m_src, int m_dst) {
    // m_src의 절반 m_dst로 옮기기 : 최대 100번 호출
    if (belts[m_src].cnt <= 1) return belts[m_dst].cnt;

    NODE* first, * last;

    int n = belts[m_src].cnt / 2;

    // m_src list에서 앞쪽부터 n개 꺼내오기 (node 연결된 형태로 젤 앞, 젤 뒷노드 주소 first, last로 얻어오기) O(N)
    belts[m_src].get_range_from_head(first, last, n);

    // first~last까지 연결된 것 m_dst list에 붙이기 : O(1)
    belts[m_dst].splice_range(first, last, n);

    return belts[m_dst].cnt;
}

int Get_Info_By_Present(int p_num) {
    // p_num번 선물의 앞 선물, 뒷 선물 정보 얻기 : O(1)    
    NODE* p = p_present[p_num]; // p_num 선물 노드 주소 얻어오기
    int a = (p->prev->prev != (NODE*)0) ? p->prev->no_present : -1; // 앞노드 정보 (앞 노드가 head 이면 -1)
    int b = (p->next->next != (NODE*)0) ? p->next->no_present : -1; // 뒷노드 정보 (뒷 노드가 tail 이면 -1)
    return a + 2 * b;
}

int Get_Info_By_Belt(int b_num) {
    // b_num번 벨트의 첫 선물, 마지막 선물, 전체 선물 개수 확인 : O(1)
    int a = (belts[b_num].head.next != &belts[b_num].tail) ? belts[b_num].head.next->no_present : -1;
    int b = (belts[b_num].tail.prev != &belts[b_num].head) ? belts[b_num].tail.prev->no_present : -1;
    int c = belts[b_num].cnt;
    return a + 2 * b + 3 * c;
}

#endif