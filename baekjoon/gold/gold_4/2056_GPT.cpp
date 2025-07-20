#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
struct task {
    int cost;
    vector<int> nexts;
    vector<int> requires;
};
vector<task> tasks;
vector<int> indegree;
vector<int> endTime;

void init() {
    cin >> N;
    tasks.resize(N + 1);
    indegree.resize(N + 1, 0);
    endTime.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int cost, cnt;
        cin >> cost >> cnt;
        tasks[i].cost = cost;

        for (int j = 0; j < cnt; ++j) {
            int pre;
            cin >> pre;
            tasks[i].requires.push_back(pre);
            tasks[pre].nexts.push_back(i);
            indegree[i]++;
        }
    }
}

void solve() {
    queue<int> que;

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            que.push(i);
            endTime[i] = tasks[i].cost;
        }
    }

    while (!que.empty()) {
        int cur = que.front(); que.pop();

        for (int next : tasks[cur].nexts) {
            endTime[next] = max(endTime[next], endTime[cur] + tasks[next].cost);
            indegree[next]--;
            if (indegree[next] == 0) {
                que.push(next);
            }
        }
    }

    cout << *max_element(endTime.begin(), endTime.end()) << endl;
}

int main() {
    init();
    solve();
}
