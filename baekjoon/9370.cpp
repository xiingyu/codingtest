#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int n,m,t;
int s,g,h;
vector<int> candidate;
vector<bool> visited;

vector<vector<int>> table;
vector<vector<int>> costs;

void init() {
    int i, st, ed, cost, temp;
    cin >> n >> m >> t;
    cin >> s >> g >> h;

    candidate.clear();
    visited.clear();    visited.resize(n+1,false);
    table.clear();      table.resize(n+1, vector<int>());
    costs.clear();      costs.resize(n+1, vector<int>());

    for(i = 0; i < m; ++i) {
        cin >> st >> ed >> cost;
        table[st].push_back(ed);
        costs[st].push_back(cost);
        table[ed].push_back(st);
        costs[ed].push_back(cost);
    }

    for(i = 0; i < t; ++i) {
        cin >> temp;
        candidate.push_back(temp);
    }
}

int bfs(int start, int goal) {
    priority_queue<int, vector<int>, greater<vector<int>>> que;

    while(!que.empty()) {

    }
}


int main() {
    cin >> T;

    return 0;
}
