#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<vector<int>> trees;
vector<bool> visited;
vector<int> dp;

void init() {
    int a,b;
    cin >> N >> R >> Q;

    trees.resize(N+1);
    dp.resize(N+1, 1);
    visited.resize(N+1, false);

    for(int i = 0; i < N-1; ++i) {
        cin >> a >> b;
        trees[a].push_back(b);
        trees[b].push_back(a);
    }
}

int dfs(const int& target) {
    int cnt = 1;
    for(int next : trees[target]) {
        if(visited[next])   continue;
        visited[next] = true;
        cnt += dfs(next);
    }
    dp[target] = cnt;

    return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int qurry;
    init();

    visited[R] = true;
    dfs(R);

    while(Q--) {
        cin >> qurry;
        cout << dp[qurry] << '\n';
    }

    return 0;
}