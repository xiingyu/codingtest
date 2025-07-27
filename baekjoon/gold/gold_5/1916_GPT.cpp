#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M, start, goal;
vector<vector<int>> nexts, costs;
vector<int> takeCosts;

void init() {
    int s, e, c;
    cin >> N >> M;

    nexts.resize(N + 1);
    costs.resize(N + 1);
    takeCosts.assign(N + 1, INT_MAX);

    for (int i = 0; i < M; ++i) {
        cin >> s >> e >> c;
        nexts[s].push_back(e);
        costs[s].push_back(c);
    }

    cin >> start >> goal;
    takeCosts[start] = 0;
}

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start}); // (거리, 노드)

    while (!pq.empty()) {
        auto [currCost, curr] = pq.top(); pq.pop();

        if (currCost > takeCosts[curr]) continue; // 이미 더 짧은 경로로 처리됨

        for (int i = 0; i < nexts[curr].size(); ++i) {
            int next = nexts[curr][i];
            int cost = costs[curr][i];
            int newCost = currCost + cost;

            if (takeCosts[next] > newCost) {
                takeCosts[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }
}
