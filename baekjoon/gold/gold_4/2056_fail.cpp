#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solved = 0;
int times = 0;
int N;
vector<bool> isSolved;
struct task {
    int cost, cnt;
    vector<int> nexts;
    vector<int> requires;
};
vector<task> tasks;
queue<int> que;

void init() {
    int i, curCost, taskCnt, beforeTask;
    vector<int> emptyVector;
    vector<int> nextVector, requireVector;
    emptyVector.clear();
    cin >> N;
    isSolved.resize(N+1, false);
    tasks.resize(N+1);

    for(int i = 1; i <= N; ++i) {
        nextVector.clear(); requireVector.clear();
        cin >> curCost >> taskCnt;
        if(i == 1) {
            tasks[i] = (task{curCost, taskCnt, nextVector, requireVector});
            que.push(i);
        }
        else if(!taskCnt) {
            tasks[i] = (task{curCost, taskCnt, nextVector, requireVector});
            que.push(i);
        }
        else {
            for(int j = 0; j < taskCnt; ++j) {
                cin >> beforeTask;
                requireVector.push_back(beforeTask);
            }
            tasks[i] = (task{curCost, taskCnt, emptyVector, requireVector});
            for(int next : requireVector) {
                tasks[next].nexts.push_back(i);
            }
        }
    }
}

void printMap() {
    for(int i = 1; i < tasks.size(); ++i) {
        cout << "i : " << i << " cost : " << tasks[i].cost;
        cout << " nexts : ";
        for(int j = 0; j < tasks[i].nexts.size(); ++j) {
            cout << tasks[i].nexts[j] << " ";
        }

        cout << " requires : ";
        for(int j = 0; j < tasks[i].requires.size(); ++j) {
            cout << tasks[i].requires[j] << " ";
        }
        cout << endl;

    }
}

void printTarget(const vector<int>& targetVector) {
    for(int i = 0; i < targetVector.size(); ++i) {
        cout << targetVector[i] << " ";
    }
    cout << endl;
}

bool isAllSolve() {
    int i;
    for(i = 1; i < isSolved.size(); ++i) {
        if(isSolved[i] == false) {
            return false;
        }
    }
    return true;
}

void bfs() {
    while(solved < N) {
        vector<int> processOnce;
        processOnce.clear();
        while(!que.empty()) {
            bool isCanProcess = true;
            int current = que.front(); que.pop();
            // cout << "current : " << current << endl;
            // if(tasks[current].requires.empty()) {
            //     isSolved[current] = true;
            //     processOnce.push_back(current);
            //     continue;
            // }
            for(int target : tasks[current].requires) {
                if(isSolved[target] == false) {
                    isCanProcess = false;
                    break;
                }
                else {
                    isCanProcess = true;
                }
            }
            if(isCanProcess) {
                bool foundDup = false;
                for(int i = 0; i < processOnce.size(); ++i) {
                    if(processOnce[i] == current) {
                        foundDup = true;
                        break;
                    }
                }
                if (!foundDup) processOnce.push_back(current);
            }
            
        }

        // printTarget(processOnce);
        int takesTime = 0;
        for(int target : processOnce) {
            isSolved[target] = true;
            takesTime = max(takesTime, tasks[target].cost);
            for(int i = 0; i < tasks[target].nexts.size(); ++i) {
                que.push(tasks[target].nexts[i]);
                // cout << "if target : " << target << "  nexts : " <<tasks[target].nexts[i] << endl;
            }
        }
        // cout << "takestime : " << takesTime << endl;
        times += takesTime;
        solved += processOnce.size();

    }
}





int main() {
    init();
    // printMap();
    bfs();
    cout << times << endl;
}