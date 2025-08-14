#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K, M;
vector<vector<int>> links;
vector<vector<int>> hyperLoops;
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
    hyperLoops.resize(N+1);

    if(K == 1) return false;

    for(int j = 0; j < M; ++j) {
        vector<int> line;
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);

        line.push_back(a);  line.push_back(b);
        befTemp = b;
        for(int i = 0; i < K-2; ++i) {
            a = befTemp;
            cin >> b;
            line.push_back(b);
            links[a].push_back(b);
            links[b].push_back(a);
            befTemp = b;
        }

        for(int target = 0; target < line.size(); ++ target) {
            for(int subTarget = 0; subTarget < line.size(); ++subTarget) {
                if(!(target == subTarget))
                    hyperLoops[line[target]].push_back(line[subTarget]);
            }
        }
    }

    que.push(node{1, 0});
    visited[1] = true;

    return true;

}

int bfs() {
    node curr;
    int next, i;

    while(!que.empty()) {
        curr = que.front(); que.pop();

        for(i = 0; i < hyperLoops[curr.n].size();++i) {
            next = hyperLoops[curr.n][i];

            if(next == N) return curr.dist + 1;
            if(visited[next] == true) continue;

            visited[next] = true;
            que.push(node{next, curr.dist + 1});
        }

        for(i = 0; i < links[curr.n].size(); ++i) {
            next = links[curr.n][i];

            if(next == N) return curr.dist + 1;
            if(visited[next] == true) continue;

            visited[next] = true;
            que.push(node{next, curr.dist + 1});

        }
    }
    return -2;
}

int main() {
    bool initFlag;
    int resultCost;

    initFlag = init();
    if(!initFlag) {
        cout << -1 << endl;
        return 0;
    }
    else {
        resultCost = bfs();
    }
    cout << resultCost+1 << endl;

}