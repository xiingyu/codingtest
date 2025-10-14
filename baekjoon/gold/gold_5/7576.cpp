#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0 ,0};

int N,M;
vector<vector<int>> table;
vector<vector<bool>> visited;

struct point{
    int y,x;
    int date;
};
queue<point> Q;

//가로 M 세로 N
void init() {
    int temp;
    cin >> M >> N;

    table.resize(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> temp;
            table[i][j] = temp;
            if(temp == 1) {
                Q.push(point{i,j,0});
                visited[i][j] = true;
            }
        }
    }

}

int BFS() {
    int result = -1;

    while(!Q.empty()) {
        point curr = Q.front(); Q.pop();

        for(int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(visited[ny][nx]) continue;
            if(table[ny][nx] == -1) continue;

            Q.push(point{ny, nx, curr.date+1});
            table[ny][nx] = 1;
            visited[ny][nx] = true;

        }
        result = curr.date;
    }

    return result;
}

bool checkTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 0) return false;
        }
    }

    return true;
}



int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    init();
    int date = BFS();
    if(date != -1) {
        if(checkTable())    cout << date;
        else                cout << -1;
    } else {
        cout << -1;
    }


    return 0;
}