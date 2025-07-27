#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K, M;
vector<vector<int>> links;
vector<bool> visited;

struct node {
    int n, dist;
};
queue<node> que;

bool init() { 
    int station, hub;
    cin >> N >> K >> M;

    links.resize(N+1 + M);
    visited.resize(N+1 + M, false);

    if(K == 1) return false;

    for(int i = 1; i <= M; ++ i) {
        for(int j = 0; j < K; ++j) {
            cin >> station;
            hub = N + i;
            links[station].push_back(hub);
            links[hub].push_back(station);
        }
    }
    return true;
}

int bfs() {
    node curr;
    int i;

    que.push(node{1,1});
    visited[1] = true;

    while(!que.empty()) {
        curr = que.front(); que.pop();

        if(curr.n == N) {
            return curr.dist;
        }

        for(int next : links[curr.n]) {
            if(visited[next] == false ) {
                visited[next] = true;

                que.push(node{next, next>N ? curr.dist : curr.dist + 1});
            }
        }
        
    }
    return -1;
}

int main() {
    bool initFlag;
    // int result;
    initFlag = init();


    if(!initFlag) {
        if(N == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    else {
        cout << bfs() << endl;
    }

}