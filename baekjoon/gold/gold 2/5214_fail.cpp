#include <iostream>
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
    int befTemp, a, b;
    cin >> N >> K >> M;

    links.resize(N+1);
    visited.resize(N+1, false);

    if(K == 1) return false;

    for(int j = 0; j < M; ++j) {
        // cout << " j!" << endl;
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
        befTemp = b;
        // cout << "a : " << a << " b : " << b << endl;
        for(int i = 0; i < K-2; ++i) {
            // cout << " k!" << endl;
            a = befTemp;
            cin >> b;
            links[a].push_back(b);
            links[b].push_back(a);
            // cout << "a : " << a << " b : " << b << endl;
            befTemp = b;
        }
    }

    que.push(node{1, 0});
    visited[1] = true;

    return true;

}

int bfs() {
    node curr, next;

    while(!que.empty()) {
        curr = que.front(); que.pop();

        for(int i = 0; i < links[curr.n].size(); ++i) {
            next = node{links[curr.n][i], curr.dist + 1};

            if(next.n == N) return next.dist;
            if(visited[next.n] == true) continue;

            visited[next.n] = true;
            que.push(next);
        }
    }
}

int main() {
    bool initFlag;
    int resultCost;

    initFlag = init();
    // cout << "init clear" << endl;
    if(!initFlag) cout << -1 << endl;
    else {
        resultCost = bfs();
    }
    cout << resultCost - 1 << endl;

}