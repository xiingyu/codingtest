#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

int N,M;
int maximum = -1;
vector<vector<int>> table;
vector<vector<bool>> visited;


void init() {
    cin >> N >> M;
    table.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> table[i][j];
        }
    }
}

void dfs(int& currY, int& currX, int depth, int sum) {
    if(depth >= 3) {
        maximum = max(sum, maximum);
        return;
    }

    int nxtY; int nxtX;
    for(int i = 0; i < 4; ++i) {
        nxtY = currY + dy[i];
        nxtX = currX + dx[i];
        if(nxtY < 0 || nxtX < 0 || nxtY >= N || nxtX >= M) continue;
        if(visited[nxtY][nxtX]) continue;

        visited[nxtY][nxtX] = true;
        dfs(nxtY, nxtX, depth + 1, sum + table[nxtY][nxtX]);
        visited[nxtY][nxtX] = false;
    }

}

void checkT(int& currY, int& currX) {
    int nxtY; int nxtX;
    int sum = table[currY][currX];

    for(int i = 0; i < 4; ++i) {
        sum = table[currY][currX];
        for(int j = 0; j < 4; ++j) {
            if(i == j)  continue;
            nxtY = currY + dy[j];
            nxtX = currX + dx[j];
            if(nxtY < 0 || nxtX < 0 || nxtY >= N || nxtX >= M) continue;
            sum += table[nxtY][nxtX];
        }
        if(sum > maximum)   maximum = sum;
    }


}

int main() {
    ios::sync_with_stdio(0);    cin.tie(0); cout.tie(0);

    init();

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            visited[i][j] = true;
            dfs(i,j,0,table[i][j]);
            visited[i][j] = false;
            checkT(i,j);
        }
    }
    
    cout << maximum;

    return 0;
}