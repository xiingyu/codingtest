#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, q;
vector<int> costs;
vector<bool> visited;
vector<vector<int>> nexts;

struct node {
    int n, dist;
};
queue<node> que;

void init() {
    int a,b;
    cin >> n >> m;
    
    visited.resize(n+1, false);
    costs.resize(n+1, 0x7FFFFFFF);
    nexts.resize(n+1);

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        nexts[a].push_back(b);
        nexts[b].push_back(a);
    }

}

int bsf(int goal) {
    node curr, next;
    while(!que.empty()) {
        curr = que.front(); que.pop();

        for(int i = 0; i < nexts[curr.n].size(); ++i) {
            next = node{nexts[curr.n][i], curr.dist + 1};
            // cout << next.n << endl;

            if(next.n == goal) {
                return next.dist;
            }

            if (visited[next.n] == false) {
                visited[next.n] = true;
                que.push(next);
            }
        }
    }

    return -1;
}

void construct() {
    int a, b;
    cin >> a >> b;
    
    nexts[a].push_back(b);
    nexts[b].push_back(a);
    cout << 0 << " ";
    for(int i = 2; i <= n; ++i) {
        
        while(!que.empty()) que.pop();
        que.push(node{1,0});
        costs[1] = 0;
        visited[1] = true;

        cout << bsf(i) << " ";

        visited.assign(n+1, false);
        costs.assign(n+1, 0x7FFFFFFF);
    }
    cout << endl;
    
}




int main() {
    int T;
    init();
    cin >> T;

    while(T--) {
        construct();

    }

    

}