#include <iostream>
#include <vector>
using namespace std;

int T,N;
int cycle = 0;
vector<int> table;
vector<bool> visited;
vector<bool> finished;

void dfs(int& curr) {
    visited[curr] = true;
    int next = table[curr];

    if(!visited[next]) {
        dfs(next);
    } else if(visited[next] && !finished[next]) {
        cycle++;
        while(curr != next) {
            next = table[next];
            cycle++;
        }
    }
    finished[curr] = true;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--) {
        cycle = 0;
        cin >> N;

        table.assign(N+1, 0);
        visited.assign(N+1, false);
        finished.assign(N+1, false);

        for(int i = 1; i < N+1; ++i) {
            cin >> table[i];
        }
        for(int i = 1; i < N+1; ++i) {
            if(!visited[i]) dfs(i);
        }

        cout << N - cycle << '\n';

    }


    return 0;
}