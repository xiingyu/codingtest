#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<vector<bool>> visited;
vector<vector<bool>> lighted;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct point {
    int x,y;
};
vector<vector<vector<point>>> nextMap;
queue<point> que;

void init() {
    int x,y,a,b, i;
    cin >> N >> M;

    visited.resize(N+1, vector<bool>(N+1, false));
    lighted.resize(N+1, vector<bool>(N+1, false));
    nextMap.resize(N+1, vector<vector<point>>(N+1));

    for(i = 0; i < M; ++i) {
        cin >> x >> y >> a >> b;
        nextMap[y][x].push_back(point{a,b});
    }

}

void bfs() {
    int i, j, nx, ny;
    que.push(point{1,1});
    visited[1][1] = true;
    lighted[1][1] = true;

    while(!que.empty()) {
        point curr = que.front();   que.pop();\

        for(const point& targetRoom : nextMap[curr.y][curr.x]) { 
            if(visited[targetRoom.y][targetRoom.x]) continue;

            lighted[targetRoom.y][targetRoom.x] = true;
\
            for(j = 0; j < 4; ++j) {
                nx = targetRoom.x + dx[j];
                ny = targetRoom.y + dy[j];
                if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

                if(visited[ny][nx]) {\
                    visited[targetRoom.y][targetRoom.x] = true;
                    que.push(targetRoom);
                    // break;
                } 
                // else if(lighted[ny][nx]) {
                    
                //     // cout << "curr : " << curr.x << " " << curr.y << endl;
                //     // cout << "pushed : " << targetRoom.x << " " << targetRoom.y << endl;
                //     visited[targetRoom.y][targetRoom.x] = true;
                //     que.push(targetRoom);
                // }
            }
            
        }
        
        for(j = 0; j < 4; ++j) {
            nx = curr.x + dx[j];
            ny = curr.y + dy[j];
            if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            if(lighted[ny][nx] && !visited[ny][nx]) {
                
                // cout << "additional" << endl;
                // cout << "pushed : " << nx << " " << ny << endl;
                visited[ny][nx] = true;
                que.push(point{nx,ny});
            }
        }
    }
}

int countLightRoom() {
    int i, j;
    int count = 0;
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j) {
            if(lighted[i][j]) count++;
        }
    }
    return count;
}

void printMap() {
    int i, j;
    int count = 0;
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j) {
            if(lighted[i][j]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j) {
            if(visited[i][j]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

}

int main() {
    init();
    bfs();
    int result = countLightRoom();
    // cout << "room check finish" << endl;

    cout << result << endl;
    // printMap();

    return 0;

}