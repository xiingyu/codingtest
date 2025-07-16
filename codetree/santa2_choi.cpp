#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
    int num;
    Box* front;
    Box* next;
};

int q, order, beltCnt, boxCnt;
vector< list<Box*>> belts;
vector< Box> boxes;

void printTotalBelt() {
    cout << "print Total" << endl;
    for (int i = 1; i < belts.size(); i++) {
        for (Box* cur : belts[i]) {

            cout << cur->num << ' ';
        }

        cout << endl;
    }
}

void printTotalBox() {
    cout << "print Total Box" << endl;
    for (int i = 1; i < boxes.size(); i++) {

        cout << i << "|  num: " << boxes[i].num << " front: ";
        if (boxes[i].front != nullptr) {
            cout << boxes[i].front->num;
        } else {
            cout << "0";
        }
        cout << " next: ";
        if (boxes[i].next != nullptr) {
            cout << boxes[i].next->num << endl;
        } else {
            cout << "0" << endl;
        }
    }
}

void buildFactory() {
    cin >> beltCnt >> boxCnt;
    vector< vector <int>> boxList(beltCnt + 1);
    belts = vector< list<Box*>> (beltCnt + 1);
    boxes = vector< Box> (boxCnt + 1);
    
    int beltInd;
    for (int i = 1; i <= boxCnt; i++) {
        cin >> beltInd;
        boxList[beltInd].push_back(i);
    }

    for (int i = 1; i <= beltCnt; i++) {
        sort(boxList[i].begin(), boxList[i].end());

        for (int cur : boxList[i]) {
            if (belts[i].size() > 0) {
                boxes[cur] = {cur, belts[i].back(), nullptr};
                belts[i].back()->next = &boxes[cur];
            } else {
                boxes[cur] = {cur, nullptr, nullptr};
            }
            belts[i].push_back(&boxes[cur]);
        }
    }
    // printTotalBelt();
    // printTotalBox();
}

void moveAllBox() {
    int src, dst;
    cin >> src >> dst;

    if (belts[src].size() > 0) {
        if (belts[dst].size() > 0) {
            belts[dst].front()->front = belts[src].back();
            belts[src].back()->next = belts[dst].front();
        }
    }
    
    belts[dst].splice(belts[dst].begin(), belts[src]);

    cout << belts[dst].size() << endl;
    // printTotalBelt();
    // printTotalBox();
}

void moveFrontBox() {
    int src, dst;
    cin >> src >> dst;
    
    Box* tmpS = nullptr;
    Box* tmpD = nullptr;
    Box* tmpSNext = nullptr;
    Box* tmpDNext = nullptr;

    if (!belts[src].empty()) {
        tmpS = belts[src].front();
        belts[src].pop_front();
    }
    if (!belts[dst].empty()) {
        tmpD = belts[dst].front();
        belts[dst].pop_front();
    }

    if (tmpS) { // src 에 요소 존재
        tmpSNext = tmpS->next;
        belts[dst].push_front(tmpS);
        tmpS->next = tmpD ? tmpD->next : nullptr;
    }
    if (tmpD) { //  dst 에 요소 존재
        tmpDNext = tmpD->next;
        belts[src].push_front(tmpD);
        tmpD->next = tmpS ? tmpSNext : nullptr;
    }

    if (tmpDNext) {
        tmpDNext->front = tmpS;
    }
    if (tmpSNext) {
        tmpSNext->front = tmpD;
    }

    cout << belts[dst].size() << endl;
}

void divideBox() {
    int src, dst;
    cin >> src >> dst;

    int half = belts[src].size() / 2;
    Box* dFront = nullptr;

    if (belts[dst].size() > 0) {
        dFront = belts[dst].front();
    }

    list<Box*> tmp;
    for (int i = 0; i < half; i++) {
        if (belts[src].size() == 0) {
            break;
        }
        
        Box* b = belts[src].front();
        belts[src].pop_front();
        tmp.push_back(b);
    }

    if (belts[src].size() > 0) {
        belts[src].front()->front = nullptr;
    }

    if (!tmp.empty()) {
        tmp.back()->next = dFront;
    }

    if (!tmp.empty() && dFront) {
        dFront->front = tmp.back();
    }

    belts[dst].splice(belts[dst].begin(), tmp);

    cout << belts[dst].size() << endl;
}

void printBox() {
    int boxInd;
    cin >> boxInd;

    int front = boxes[boxInd].front == nullptr ? -1 : boxes[boxInd].front->num;
    int next = boxes[boxInd].next == nullptr ? -1 : boxes[boxInd].next->num;

    cout << front + (2 * next) << endl;
}

void printBelt() {
    int beltInd;
    cin >> beltInd;
    list<Box*>& curBelt = belts[beltInd];
    
    int size = curBelt.size();
    int front = size > 0 ? curBelt.front()->num : -1;
    int back = size > 0 ? curBelt.back()->num : -1;
    
    cout << front + (2 * back) + (3 * size) << endl;
}

int main() {
    cin >> q;

    while (q--) {
        cin >> order;
        switch (order) {
            case 100:
                buildFactory();
            break;
            case 200:
                moveAllBox();
            break;
            case 300:
                moveFrontBox();
            break;
            case 400:
                divideBox();
            break;
            case 500:
                printBox();    
            break;
            default:
                printBelt();
            break;
        }
    }

    return 0;
}