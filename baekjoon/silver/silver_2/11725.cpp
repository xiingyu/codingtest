#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> table;
vector<int> parents;

void init() {
    int a,b;
    cin >> N;

    table.resize(N+1);
    parents.resize(N+1, 0);

    for(int i = 0; i < N-1; ++i) {
        cin >> a >> b;
        table[a].push_back(b);
        table[b].push_back(a);
    }
}

void dfs(const int start, const int bef) {
    for(int target : table[start]) {
        if(target == bef) continue;
        // cout << target;
        parents[target] = start;
        dfs(target, start);
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    dfs(1,0);

    for(int i = 2; i <= N; ++i) {
        cout << parents[i] << '\n';
    }

    return 0;
}