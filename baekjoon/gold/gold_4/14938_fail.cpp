#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int N,M,R;
int maxScore = INF;
vector<int> scores;
vector<vector<int>> table;

void init() {
    int a,b,c;
    cin >> N >> M >> R;
    scores.resize(N+1);
    for(int i = 1; i <= N; ++i) {
        cin >> scores[i];
    }

    table.resize(N+1, vector<int>(N+1, INF));
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> a >> b >> c;
            table[a][b] = min(table[a][b], c);
            table[b][a] = min(table[b][a], c);
        }
    }
}

int dfs(int s, int cost, int point, vector<int>& visited) {
    int totalScore = scores[s];

    cout << "s : " <<  s  << " cost : " << cost  << " point : "  << point << endl;
    
    for(int i = 1; i <= N; ++i) {
        if(visited[i])  continue;
        if(table[s][i] != INF) {
            if(cost + table[s][i] > M) continue;
            

            visited[i] = true;
            // totalScore = max(dfs(i, cost + table[s][i], point + scores[i], visited), totalScore);
            // totalScore += scores[i];
            // dfs(i, cost + table[s][i], totalScore, visited);
            totalScore += dfs(i, cost + table[s][i], point + scores[i], visited);
            cout << "s : " << s << " total : " << totalScore <<endl;
            visited[i] = false;
            // totalScore -= scores[i];

        }

    }
    // cout << totalScore << endl;
    return totalScore;
}

int main() {
    int maxScore = 0;
    vector<int> visited;

    init();
    visited.resize(N+1, false);
    // for(int i = 1; i <= N; ++i) {
    //     // cout << "number " << i << " start!" << endl;
    //     visited[i] = true;
    //     maxScore = max(maxScore, dfs(i, 0, scores[i], visited));
    //     visited[i] = false;
    // }
        int i = 1;
        visited[i] = true;
        maxScore = max(maxScore, dfs(i, 0, scores[i], visited));
        visited[i] = false;

    cout << maxScore;

    return 0;
}