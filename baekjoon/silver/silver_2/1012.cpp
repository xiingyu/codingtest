#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int M,N,K;
vector<vector<int>> table;
vector<vector<bool>> visited;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

// in은 x,y 순
void init() {
    int a,b;
    cin >>M >> N >> K;

    table.clear();  table.resize(N, vector<int>(M, 0));
    visited.clear();  visited.resize(N, vector<bool>(M, false));

    while(K--) {
        cin >> a >> b;
        table[b][a] = 1;
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> que;
    que.push(make_pair(y,x));
    visited[y][x] = true;

    int cx,cy, nx,ny;
    while(!que.empty()) {
        cy = que.front().first; cx = que.front().second; que.pop();

        for(int i = 0; i < 4; ++i) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if(ny >= N || nx >= M || ny < 0 || nx < 0)  continue;
            if(visited[ny][nx] == false && table[ny][nx] == 1) {

                que.push(make_pair(ny,nx));
                visited[ny][nx] = true;
            }
        }
    }

}

int searchBaeChu() {
    int i,j;
    int bugs = 0;

    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            if(visited[i][j] == true)   continue;
            if(table[i][j] == 1) {
                // cout << "걸려들었어! " << j << " " << i << endl;
                bfs(i,j);
                bugs += 1;
            }
            else {
                visited[i][j] = true;
            }
        }
    }


    return bugs;

}

int main() {
    int temp;
    vector<int> results;
    cin >> T;
    while(T--) {
        init();
        // cout << "init clear" << endl;
        temp = searchBaeChu();
        results.push_back(temp);
    }

    for(int result : results) cout << result << "\n";

    return 0;
}