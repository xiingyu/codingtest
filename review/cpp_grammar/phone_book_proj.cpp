// addr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
class Member {
    string name;
    string tel;
    string address;
public:
    Member() {}
    Member(string name, string tel, string address) {
        this->name = name;
        this->tel = tel;
        this->address = address;
    }
    string getName() {
        return name;
    }
    void setTel(string tel) {
        this->tel = tel;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void print() {
        cout << "name:" << name << endl;
        cout << "tel:" << tel << endl;
        cout << "address:" << address << endl;
    }
};
class MemDao {
    Member* arr[30];
public:
    int cnt = 0;
    void insert(Member* m) {
        if (cnt >= 29) {
            cout << "배열참" << endl;
            return;
        }
        arr[cnt++] = m;
    }
    int selectByName(string name) {
        int i;
        for (i = 0; i < cnt; i++) {
            if (name == arr[i]->getName()) {
                return i;
            }
        }
        return -1;
    }

    Member* selectByIdx(int idx) {
        if (idx >= cnt || idx < 0) {
            cout << "잘못된 인덱스" << endl;
            return NULL;
        }
        else {
            return arr[idx];
        }
    }

    bool update(Member* m) {
        int idx = selectByName(m->getName());
        if (idx < 0) {
            return false;
        }

        delete arr[idx];//기존 객체를 삭제
        arr[idx] = m; //새 객체 삽입
        return true;
    }

    bool del(string name) {
        int idx = selectByName(name);
        if (idx < 0) {
            return false;
        }
        cout << "객체 삭제됨" << endl;
        arr[idx]->print();

        delete arr[idx];
        for (int i = idx; i < cnt - 1; i++) {
            arr[i] = arr[i + 1];
        }
        cnt--;
    }
    //모든 노드 삭제
    void delAll() {
        for (int i = 0; i < cnt; i++) {
            delete arr[i];
        }
    }
};
//기능 제공
class Service {
    MemDao dao;
public:
    void add() {
        cout << "추가" << endl;
        string name;
        cout << "name:";
        cin >> name;
        int idx;
        while ((idx = dao.selectByName(name)) >= 0) {
            cout << "이름 중복. 다시 입력하시오" << endl;
            cin >> name;
        }
        string tel;
        cout << "tel:";
        cin >> tel;

        string address;
        cout << "address:";
        cin >> address;

        dao.insert(new Member(name, tel, address));
    }

    void printAll() {
        cout << "전체목록" << endl;
        for (int i = 0; i < dao.cnt; i++) {
            dao.selectByIdx(i)->print();
        }
    }

    void getByName() {
        cout << "이름으로 검색" << endl;
        string name;
        cout << "name:";
        cin >> name;
        Member* m = dao.selectByIdx(dao.selectByName(name));
        if (m != NULL) {
            m->print();
        }
    }

    void edit() {
        cout << "수정" << endl;
        string name;
        cout << "name:";
        cin >> name;
        string tel;
        cout << "new tel:";
        cin >> tel;
        string addr;
        cout << "new address:";
        cin >> addr;
        if (dao.update(new Member(name, tel, addr))) {
            cout << "수정 완료" << endl;
        }
        else {
            cout << "수정 취소" << endl;
        }
    }
    void del() {
        cout << "삭제" << endl;
        string name;
        cout << "name:";
        cin >> name;
        if (dao.del(name)) {
            cout << "삭제 완료" << endl;
        }
        else {
            cout << "삭제 취소" << endl;
        }
    }
    void delAll() {
        dao.delAll();
    }
};
int main()
{
    Service s;
    bool flag = true;
    int x;
    while (flag) {
        cout << "1.추가 2.검색 3.수정 4.삭제 5.전체목록 6.종료" << endl;
        cin >> x;
        switch (x) {
        case 1:
            s.add();
            break;
        case 2:
            s.getByName();
            break;
        case 3:
            s.edit();
            break;
        case 4:
            s.del();
            break;
        case 5:
            s.printAll();
            break;
        case 6:
            flag = false;
            s.delAll();
            break;
        }
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
