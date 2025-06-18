#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N (100+2)
typedef struct _node {
    int r;
    int c;
}node;
int C, R;  // 열, 행
int sc, sr;// 열번호, 행번호
int map[MAX_N][MAX_N];  // 입력, 방문표시(3, 4, 5, ...)

node Queue[MAX_N * MAX_N];
int front, rear;
//void enqueue(int r, int c) {
//    Queue[rear].r = r;
//    Queue[rear].c = c;
//    ++rear;
//}

void enqueue(int r, int c) {
    Queue[rear++] = (node){ r, c };
}

node dequeue(void) {
    return Queue[front++];
}

// 디버깅 용도
static void printMap(void) {

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int BFS(int sr, int sc) {
    node curr = { 0 };
    int nr, nc, time=0;

    front = rear = 0;
    enqueue(sr, sc);
    map[sr][sc] = 3;

    while (front != rear) {
        curr = dequeue();
        time = map[curr.r][curr.c];
        for (int i = 0; i < 4; ++i) {
            nr = curr.r + dr[i];
            nc = curr.c + dc[i];
            if (map[nr][nc] == 1) {
                enqueue(nr, nc);
                map[nr][nc] = time + 1;
            }
        }
    }
    printMap();
    return time;
}

static void inputData(void) {
    char temp[MAX_N] = { 0 };
    (void)scanf("%d %d", &C, &R);
    for (int i = 1; i <= R; i++) {
        (void)scanf("%s", temp + 1);
        int* pTmp = map[i];
        for (int j = 1; j <= C; j++) {
            pTmp[j] = temp[j] - '0';
        }
    }
    (void)scanf("%d %d", &sc, &sr);
}



// 저글링 방사능 오염 - https://jungol.co.kr/problem/1078
void J1078_solution(void) {
    (void)freopen("J1078.txt", "r", stdin);
    inputData();
    printMap();
    printf("%d\n", BFS(sr, sc));
}




#if 0 // 오류수정 요

#include <stdio.h>
#define MAX_N (100+2)

typedef struct _node {
    int r;
    int c;
}node;

int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];

node Queue[MAX_N * MAX_N];
int front, rear;
int C, R;                   // 열 행
int N, M;                   // 열 행
int sc, sr;                 // 열 행

//expression1
// void enqueue(int r, int c, int value) {
//     Queue[rear].r = r;
//     Queue[rear].c = c;
//     Queue[rear].value = value;
//     ++rear;
// }


//expression2
void enqueue(int r, int c) {
    Queue[rear++] = (node){ r, c};
}

node dequeue(void) {
    return Queue[front++];
}


void inputData(void) {
    char temp[MAX_N] = { 0 };
    scanf("%d", &N);

    for (int i = 1; i <= R; i++) {
        (void)scanf("%s", temp+1);
        int* pTmp = map[i];
        for (int j = 1; j <= C; j++) {
            pTmp[j] = temp[j] - 48;
        }
    }
    (void)scanf("%d %d", &sc,&sr);
}

int dr[] = {1, -1, 0, 0}; // 상하좌우
int dc[] = {0, 0, 1. -1};

int BFS(int sr, int sc) {
    node curr = {0};
    int nr,nc, time;

    front = rear = 0;
    enqueue(sr,sc);
    map[sr][sc] = 3;

    while(front != rear) {
        curr = dequeue();
        for (int i = 0; i < 4; ++i) {
            nr = curr.r + dr[i];
            nc = curr.c + dc[i];
            time = map[curr.r][curr.c];
            if (map[nr][nc] == 1) {
                enqueue(nr,nc);
                map[nr][nc] = time +1;
            }
        }
    }

    return 0;
}

static void printMap(void) {
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(void) {
    inputData();
    BFS(sr,sc);
    printMap();
}

#endif