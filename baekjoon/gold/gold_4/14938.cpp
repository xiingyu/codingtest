#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int N, M, R;
vector<int> scores;
vector<vector<int>> table;
// vector<vector<int>> nxt;

void init() {
    int a,b,c;
    cin >> N >> M >>R;

    scores.resize(N+1, 0);
    for(int i = 1; i <=N; ++i) {
        cin >> scores[i];
    }

    table.resize(N+1, vector<int>(N+1, INF));
    // nxt.resize(N+1, vector<int>(N+1, 0));

    for(int i = 1; i <= R; ++i) {
        cin >> a >> b >> c;
        table[a][b] = min(table[a][b], c);
        table[b][a] = min(table[b][a], c);
        // nxt[a][b] = b; nxt[b][a] = a;
    }
}

void logic() {
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <=N; ++i) {
            for(int j = 1; j <=N; ++j) {
                if(table[i][k] + table[k][j] < table[i][j]) {
                    table[i][j] = table[i][k] + table[k][j];
                    // nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}



int main() {
    init();
    logic();

    int cnt, answer = 0;

    for(int i = 1; i < N+1; ++i) {
        cnt = scores[i];
        for(int j = 1; j < N+1; ++j) {
            if(i != j && table[i][j] <= M) {
                cnt += scores[j];
            }
        }
        answer = max(answer, cnt);
    }

    cout << answer;

}
