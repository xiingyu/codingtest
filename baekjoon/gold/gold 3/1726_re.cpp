#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m,n;
vector<vector<vector<bool>>> visited;
vector<vector<int>> map;

struct point {
    int y,x,dir,cnt;
};
queue<point> que;
point start, goal, result;

int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

void input() {
    int i, j, temp, tempY, tempX, tempDir;
    cin >> m >> n;
    map.resize(m, vector<int>(n));
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            cin >> temp;
            map[i][j] = temp;
        }
    }
    cin >> tempY >> tempX >> tempDir;
    start = point{tempY -1 , tempX - 1, tempDir, 0};
    cin >> tempY >> tempX >> tempDir;
    goal = point{tempY- 1, tempX - 1, tempDir, 0};
    
}

void bfs() {
    que.push(start);
    visited[start.dir][start.y][start.x] = true;

    while(!que.empty()) {
        point curr = que.front(); que.pop();
        // cout << "curr: " << "y: " << curr.y << " x: " << curr.x << " dir: " << curr.dir <<  " cnt: " << curr.cnt << endl;

        if(curr.y == goal.y && curr.x == goal.x && curr.dir == goal.dir) {
            result = curr;
            break;
        }
        int nx, ny;

        // foward
        // cout << "forward" << endl;
        for(int i = 1; i <= 3; ++i) {
            nx = curr.x + dx[curr.dir] * i;
            ny = curr.y + dy[curr.dir] * i;

            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[ny][nx] == 1) {
                break;
                }
            else {
                if (visited[curr.dir][ny][nx] == true)
                    continue;
                visited[curr.dir][ny][nx] = true;
                que.push(point{ny, nx, curr.dir, curr.cnt + 1});
                // cout << "next: " << "y: " << ny << " x: " << nx << " dir: " << curr.dir << " cnt: " << curr.cnt + 1 << endl; 
            }
        }
        
        // turn
        // cout << "turn" << endl;
        if (curr.dir == 1 || curr.dir == 2) {
            for(int j = 3; j <= 4; ++j) {
            if (visited[j][curr.y][curr.x] == true) continue;
            visited[j][curr.y][curr.x] = true;
            que.push(point{curr.y, curr.x, j, curr.cnt + 1});
            }
        }

        if (curr.dir == 3 || curr.dir == 4) {
            for(int j = 1; j <= 2; ++j) {
            if (visited[j][curr.y][curr.x] == true) continue;
            visited[j][curr.y][curr.x] = true;
            que.push(point{curr.y, curr.x, j, curr.cnt + 1});
            }
        }
        
        // cout << endl;
    }

}

void printMap() {
    int i,j,k;
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    input();
    visited.resize(5, vector<vector<bool>>(m, vector<bool>(n,false)));
    bfs();
    // printMap();
    cout << result.cnt;


}