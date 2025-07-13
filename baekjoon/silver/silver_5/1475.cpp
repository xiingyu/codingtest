#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<char> que;
vector<int> cnt(10,0);
int target;

void countSet() {
    
    while(!que.empty()) {
        char current = que.front();
        que.pop();
        // cout << (int)(current) << " ";
        cnt[(int)(current) - (int)'0'] +=1;
    }
}

void printMap() {
    for(int i = 0; i < cnt.size(); ++i) {
        cout << cnt[i] << " ";
    }
}

int findMax() {
    cnt[6] += cnt[9];
    int maxCnt = 0;
    for(int i = 0; i < 9; ++i) {
        if (i == 6) {
            if(cnt[6] % 2 == 0) cnt[6] = cnt[6] / 2;
            else cnt[6] / 2 + 1;
        }
        maxCnt = max(maxCnt, cnt[i]);
    }
    return maxCnt;
}

int main(void) {
    cin >> target;
    for(char num : to_string(target)) {
        que.push(num);
    }
    countSet();
    // printMap();
    int maxCnt = findMax();
    cout << maxCnt;
    
}


