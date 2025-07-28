#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, X;
int cost = 1;
queue<int> que;
vector<int> dist;
vector<bool> visited;
vector<vector<int>> nexts;

void init() {
    int i, s, e;
    cin >> N >> M >> K >> X;

    dist.resize(N+1, 0x7FFFFFFF);
    visited.resize(N+1, false);
    nexts.resize(N+1);

    for(i = 0; i < M; ++i) {
        cin >> s >> e;
        nexts[s].push_back(e);
    }
    dist[X] = 0;
    que.push(X);
}

void dijkstra() {

    while(!que.empty()) {
        int curr = que.front(); que.pop();
        visited[curr] = true;
        // cout << "curr : " << curr << endl;

        for(int future : nexts[curr]) {
            if(visited[future] == false) {
                dist[future] = min(dist[future], dist[curr] + cost);
                que.push(future);
                // cout << "future : " << future << endl;
            }
        }
    }
}

void printMap() {
    for(int i = 0; i < dist.size(); ++i) {
        cout << dist[i] << endl;
    }
}

int main() {
    vector<int> result; result.push_back(-1);
    init();
    dijkstra();

    for(int i = 1; i < dist.size(); ++i) {
        if(dist[i] == K) {
            result.push_back(i);
        }
    }
    
    int start = result.size() == 1 ? 0 : 1;
    for(int i = start; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    // printMap();

}