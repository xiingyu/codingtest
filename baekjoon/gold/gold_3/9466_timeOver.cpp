#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int T;
int ans;

void printVector(const vector<int>& arr) {
    for(int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}


bool dfs(const int& start, int& curr, const vector<int>& table, vector<int>& teams, vector<bool>&visited) {
    visited[curr] = true;
    int next = table[curr];
    if(next == curr) {
        teams[next] = 1;
        ans++;
        return false;
    } else if(next == start) {
        teams[curr] = 1;
        ans++;
        return true;
    } else if(teams[next]  != INF) {
        return false;
    }

    if(!visited[next] && dfs(start, next, table, teams, visited)) {
        teams[curr] = 1;
        ans++;
        return true;
    }
    
    return false;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    vector<int> table;
    vector<int> teams;
    vector<bool> visited;

    cin >> T;
    while(T--){
        ans = 0;
        cin >> N;
        table.assign(N+1, 0);
        teams.assign(N+1, INF);
        visited.assign(N+1, false);
        for(int i = 1; i <= N; ++i) {
            cin >> table[i];
        }
        for(int i = 1; i < N+1; ++i) {
            if(teams[i] == INF) {
                visited.assign(N+1, false);
                dfs(i, i, table, teams, visited);
            }
        }

        // for(int i = 1; i < N+1; ++i)
        //     if(teams[i] == INF) ans++;

        // printVector(teams);
        // printVector(table);
        cout << N - ans << '\n';
    }

    return 0;
}