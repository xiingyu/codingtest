#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// vector<array<deque<int>, 2>> gears(4);
vector<unsigned short int> gears;
int dx[] = {-1, 1};
struct cir {
    int targetNum, direction;
};


void init() {
    string temp;
    gears.resize(4, 0);
    for(int i = 0; i < 4; ++i) {
        cin >> temp;
        unsigned short x = 0;
        for(char c : temp) x = (x << 1) | (c - '0');
        gears[i] = x;          // 0~255
        
    }

}

void circul(int dir, int num) {
    queue<cir> que;
    que.push(cir{num,dir});
    vector<bool> visited(4, false);

    cir curr = que.front();
    visited[curr.targetNum] = true;
    
    while(!que.empty()) {
        cir curr = que.front(); que.pop();

        for(int i = 0; i < 2; ++i) {
            cir next;
            next.targetNum = curr.targetNum + dx[i];

            if(next.targetNum < 0 || next.targetNum >= 4 || visited[next.targetNum])   continue;

            if(i == 0) {
                if((((gears[curr.targetNum] & (0x1 << 1)))>>1) != ((gears[next.targetNum] & (0x1 << 5))>>5)) {
                    next.direction = (curr.direction == 1 ? -1 : 1);
                    visited[next.targetNum] = true;
                    que.push(next);
                }
            } else if(i == 1) {
                if((((gears[curr.targetNum] & (0x1 << 5)))>>5) != ((gears[next.targetNum] & (0x1 << 1))>>1)) {
                    next.direction = (curr.direction == 1 ? -1 : 1);
                    visited[next.targetNum] = true;
                    que.push(next);
                }

            } else {
                cout << "error\n";
            }

        }

        if(curr.direction == 1) {
            unsigned short int temp = (gears[curr.targetNum] & 0x1);
            gears[curr.targetNum] = (gears[curr.targetNum] >> 1) | (temp << 7);
        } else {
            unsigned short int temp = (gears[curr.targetNum] & (0x1 << 7));
            gears[curr.targetNum] = (gears[curr.targetNum] << 1) | (temp >> 7);
        }

    }
    
}

int score() {
    int scores = 0;
    for(int i = 0; i < 4; ++i) {
        if(gears[i] & (1<<7)) scores += (1<<i);
    }

    return scores;
}

void printMap() {
    for(int i = 0; i < 4; ++i) {
        for(int b = 7; b >= 0; --b) cout << ((gears[i] >> b) & 1);
        cout << "\n";
    }
    cout << "----\n";
}


int main() {
    int N, number, direction;

    init();
    cin >> N;

    while(N--) {
        cin >> number >> direction;
        number--;
        circul(direction, number);

        // printMap();
    }

    cout << score();

    return 0;
}