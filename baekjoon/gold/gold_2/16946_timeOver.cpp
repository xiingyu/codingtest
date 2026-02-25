/// 단순 scan으로 가니 시간초과. dp를 좀 곁들여볼까 함.
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dy[] = {0, 0, -1 ,1};
int dx[] = {-1, 1, 0 ,0};

int N,M;
vector<vector<int>> ans;
vector<vector<int>> table;
struct point{
    int y,x;
};
vector<vector<bool>> visited;

void init() {
    string s;
    cin >> N >> M;

    table.resize(N, vector<int>(M, 0));
    ans.resize(N, vector<int>(M, 0));
    visited.resize(N, vector<bool>(M, false));
    for(int i = 0; i < N; ++i) {
        cin >> s;
        for(int j = 0; j < M; ++j) {
            table[i][j] = (int)(s[j] - '0');
        }
    }
}

int bfs(const point& target) {
    int cnt = 1;
    queue<point> que;
    visited.assign(N, vector<bool>(M, false));
    que.push(target);   visited[target.y][target.x] = true;

    while(!que.empty()) {
        point curr = que.front();   que.pop();

        for(int i = 0; i < 4; ++i) {
            point next = {curr.y + dy[i], curr.x + dx[i]};
            if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= M) continue;
            if(table[next.y][next.x] == 1)  continue;
            if(visited[next.y][next.x]) continue;

            visited[next.y][next.x] = true;
            que.push(next);
            cnt++;
        }

    }

    return cnt;

}

void scan() {
    int temp = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 1) {
                temp = bfs(point{i,j});
                ans[i][j] = temp;
            }
            
        }
    }

}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    scan();
    printTable();

    return 0;
}