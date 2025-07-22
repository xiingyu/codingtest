#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;
int N;
queue<int> que;
vector<int> costs;
vector<int> inDegree;
vector<int> endTime;
vector<vector<int>> nextNodes;

void init() {
    int cost, degrees, requireNode;
    cin >> N;

    costs.resize(N+1, 0);
    inDegree.resize(N+1, 0);
    endTime.resize(N+1, 0);
    nextNodes.resize(N+1, vector<int>());

    for(int i = 1; i < N+1; ++i) {
        cin >> cost >> degrees;
        costs[i] = cost;
        if(degrees > 0) {
            for(int j = 0; j < degrees; ++j) {
                cin >> requireNode;
                nextNodes[requireNode].push_back(i);
                inDegree[i] += 1;
            }
        }
        else {
            que.push(i);
            // cout << i << " is pushed " << endl;
        }
    }

}

void logic() {
    int target, next;
    while(!que.empty()) {
        target = que.front(); que.pop();
        // cout << "target : " << target << endl;

        if(target == 1) {
            endTime[target] = costs[target];
        }

        if(!nextNodes[target].empty()) {
            for(int i = 0; i < nextNodes[target].size(); ++i) {
                next = nextNodes[target][i];
                endTime[next] = max(endTime[next], endTime[target] + costs[next]);
                inDegree[next] -= 1;
                if(inDegree[next] == 0) {
                    que.push(next);
                    // cout << next << " next pushed " << endl;
                }
            }
        }
        else {
                endTime[target] = max(costs[next], endTime[target]);
        }
    }

}

void printMap() {
    int i,j,k;
    for(i = 0; i < endTime.size(); ++i) {
        cout << endTime[i] << " ";
    }
    cout << endl;
}

int main() {
    init();
    logic();
    // printMap();
    cout << *max_element(endTime.begin(),endTime.end()) << endl;
}