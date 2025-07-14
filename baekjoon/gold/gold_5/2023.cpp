#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, cross;
vector<vector<int>> alpha;
vector<int> targets;

void input() {
    int i;
    char from, to;
    cin >> n >> cross;
    alpha.resize(n);
    for(i = 0; i < cross; ++i) {
        cin >> from >> to;
        // cout << (int)'A' << " ";
        alpha[(int)from - (int)'A'].push_back((int)to - (int)'A');
    }
}

void removeTarget(void) {
    int targetNum;
    char target;
    cin >> targetNum;
    for(int i = 0; i < targetNum; ++i) {
        cin >> target;
        alpha[(int)target - (int)'A'].clear();
        targets.push_back((int)target - (int)'A');
    }
}

bool isInTargets(int num) {
    for(int i = 0; i < targets.size(); ++i) {
        if(num == targets[i]) return true;
    }
    return false;
}

void printMap() {
    int i, j;
    for(i = 0; i < alpha.size(); ++i) {
        for(j = 0; j < alpha[i].size(); ++j) {
            cout << alpha[i][j] << " ";
        }
        cout << endl;
    }
}

int bfs() {
    int maxPeople = 0;
    queue<int> que;
    for(int i = 0; i < n; ++i){
        if(alpha[i].empty()) continue;
        que.push(i);
        int people = 0;
        vector<bool> visited(n,false);
        while(!que.empty()) {
            int cTarget = que.front();
            que.pop();
            if(visited[cTarget] == false) {
                // cout << "i : " << i << " cTarget : " << cTarget << endl;
                visited[cTarget] = true;
                if(!isInTargets(cTarget))
                    people += 1;
                for(int j = 0; j < alpha[cTarget].size(); ++j) {
                    // cout << "i : " << i << " alpha[cTarget][j] : " << alpha[cTarget][j] << " people : " << people << endl;
                    que.push(alpha[cTarget][j]);
                    // cout << "i : " << i << " cTarget : " << cTarget << " j : " << j << " people : " << people << endl;
                }
            }
        }
        if(people == 3) {
            cout << i;
        }
        maxPeople = max(people, maxPeople);
    }
    return maxPeople;
}

int main(void) {
    input();
    removeTarget();
    int maxPeople = bfs();
    // printMap();
    cout << maxPeople-1;


}