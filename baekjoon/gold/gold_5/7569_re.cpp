#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<vector<int>>> table;
vector<vector<vector<bool>>> visited;
int m, n, h;

int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {-1, 1, 0, 0, 0, 0};

struct target {
    int x, y, z;
};

bool que_flag = false;
queue<target> que0;
queue<target> que1;

// 모든 토마토가 익었는지 확인
bool is_all_ripe() {
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                if (table[i][j][k] == 0) return false;
    return true;
}

// 입력받기
void get_table() {
    table.resize(h, vector<vector<int>>(n, vector<int>(m)));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                cin >> table[i][j][k];
}

// BFS 1단계 수행
void bfs() {
    queue<target>& curr = que_flag ? que1 : que0;
    queue<target>& next = que_flag ? que0 : que1;

    while (!curr.empty()) {
        target now = curr.front(); curr.pop();
        int x = now.x, y = now.y, z = now.z;

        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= n || nz >= m)
                continue;
            if (visited[nx][ny][nz]) continue;
            if (table[nx][ny][nz] != 0) continue;

            visited[nx][ny][nz] = true;
            table[nx][ny][nz] = 1;
            next.push({nx, ny, nz});
        }
    }

    que_flag = !que_flag;
}

// 깊이 계산 (재귀 BFS)
int depth_cnt(int depth) {
    if (is_all_ripe()) return depth;
    if (que0.empty() && que1.empty()) return -1;

    bfs();
    return depth_cnt(depth + 1);
}

int main() {
    cin >> m >> n >> h;
    get_table();

    visited.resize(h, vector<vector<bool>>(n, vector<bool>(m, false)));

    // 초기 익은 토마토 큐에 넣기
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                if (table[i][j][k] == 1) {
                    que0.push({i, j, k});
                    visited[i][j][k] = true;
                }
                else if (table[i][j][k] == -1) {
                    visited[i][j][k] = true; // 빈 칸도 방문 처리
                }

    cout << depth_cnt(0) << endl;
}
