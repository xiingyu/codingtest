#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int T;

void printTable(vector<int>& teams, int n) {
    for(int i = 1; i < n+1; ++i) {
        cout << teams[i] << " ";
    }
    cout << endl;
}

int logic(const int& n, const vector<int>&table, vector<int>& teams) {
    int ans = 0;
    int team = 1;
    vector<bool> visited(n+1, false);

    int next;   int curr;
    
    for(int i = 1; i < n+1; ++i) {
        if(table[i] < team) continue;
        queue<int> backup;
        curr = i;
        
        while(true) {
            next = table[curr];
            if(teams[next] == team) {
                team++;
                break;
            } else if(teams[next] == INF) {
                teams[next] = team;
                backup.push(next);
                curr = next;
            } else {
                while(!backup.empty()) {
                    int target = backup.front();    backup.pop();
                    teams[target] = INF;
                }
                break;
            }
        }
    }

    for(int i = 1; i < n+1; ++i) {
        if(teams[i] == INF)   ans++;
    }
    // printTable(teams,n);


    return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    vector<int> table;
    vector<int> teams;

    cin >> T;
    while(T--){
        cin >> N;
        table.assign(N+1, 0);
        teams.assign(N+1, INF);
        for(int i = 1; i <= N; ++i) {
            cin >> table[i];
        }
        cout << logic(N, table, teams) << '\n';
    }

    return 0;
}