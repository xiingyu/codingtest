#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int w,h;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int turnRight[] = {2, 3, 1, 0};
int turnLeft[] = {3, 2, 0, 1};

vector<vector<vector<bool>>> visited;
vector<vector<short int>> map;

struct point{
    int y, x, dir, cnt;
};
queue<point> que;
point start, goal;
point result = point{0,0,0,0};

void input() {
    int i,j;
    char temp;
    bool startFlag = false;
    cin >> w >> h;
    map.resize(h, vector<short int>(w, 0));
    for(i = 0; i < h; ++i) {
        cin.get(temp);
        for(j = 0; j < w; ++j) {
            cin.get(temp);
            if(temp == '.') map[i][j] = 0;
            else if (temp == '*') map[i][j] = 1;
            else {
                //여기서 start, goal 받고
                if (!startFlag) {
                    start = point{i,j,0,0};
                    startFlag = ~startFlag;
                }
                else goal = point{i,j,0,0};
            }
        }
    }
}

void bfs() {
    for(int i = 0; i < 4; ++i) {
        que.push(point{start.y, start.x, i, 0});
        visited[i][start.y][start.x] = true;
    }
    while(!que.empty()) {
        point curr = que.front();   que.pop();
        if(curr.y == goal.y && curr.x == goal.x) {
            result = curr;
            break;
        }

        int nx,ny,nd;
        //forward
        for(int i = 1;; ++i) {
            nx = curr.x + dx[curr.dir] * i;
            ny = curr.y + dy[curr.dir] * i;

            if(nx < 0 || ny < 0 || nx >= w || ny >= h || map[ny][nx] == 1) break;
            // if(ny == goal.y && nx == goal.x) break;
            if(visited[curr.dir][ny][nx] == true) continue;

            que.push(point{ny, nx, curr.dir, curr.cnt});
            visited[curr.dir][ny][nx] = true;
        }
        

        //turn
        nx = curr.x;
        ny = curr.y;
        nd = turnRight[curr.dir];
        if(!(visited[nd][ny][nx] == true)) {
            que.push(point{ny,nx,nd, curr.cnt + 1});
            visited[nd][ny][nx] = true;
        }
        
        nd = turnLeft[curr.dir];
        if(!(visited[nd][ny][nx] == true)) {
            que.push(point{ny,nx,nd, curr.cnt + 1});
            visited[nd][ny][nx] = true;
        }

    }


}

void printMap() {
    int i,j;
    for(i = 0; i < h; ++i) {
        for(j = 0; j < w; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "sy : " << start.y << " sx : " << start.x << endl;
    cout << "gy : " << goal.y << " gx : " << goal.x << endl;

}

int main() {
    input();
    visited.resize(4, vector<vector<bool>>(h, vector<bool>(w, false)));
    bfs();
    cout << result.cnt;

}
