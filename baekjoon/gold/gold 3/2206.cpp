#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
struct point {
    int y,x,cost;
    bool skill;
};
queue<point> que;
vector<vector<vector<bool>>> visited;   //without Skill 0, with skill 1.
vector<vector<int>> table;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void init() {
    int i,j;
    string stringTemp;
    cin >> N >> M;

    visited.resize(N+1, vector<vector<bool>>(M+1, vector<bool>(2, false)));
    table.resize(N+2, vector<int>(M+2, 0));

    for(i = 1; i <= N; ++i) {
        cin >> stringTemp;
        for(j = 0; j < stringTemp.size(); ++j) {
            table[i][j+1] = stringTemp[j] - '0';
        }
    }
    
    for(i = 0; i <= N+1; ++i) {
        for(j = 0; j <= M+1; ++j) {
            if(i == 0 || i == N+1 || j == 0 || j == M+1) {
                table[i][j] = 2;
            }
        }
    }
}

int bfs() {
    point curr;
    int ny, nx, i;
    int result = -1;
    que.push(point{1,1,1,false});
    visited[1][1][0] = true;

    while(!que.empty()) {
        curr = que.front();     que.pop();
        // cout << curr.y << " " << curr.x << endl;

        if(curr.y == N && curr.x == M) {
            result = curr.cost;
            break;
        }

        for(i = 0; i < 4; ++i) {
            nx = curr.x + dx[i];
            ny = curr.y + dy[i];
            // cout << ny << " " << nx << endl;

            if(table[ny][nx] == 2) continue;
            if(visited[ny][nx][curr.skill == false ? 0 : 1]) continue;
            if(table[ny][nx] == 1) {
                if(curr.skill) continue;
                else {
                    visited[ny][nx][1] = true;
                    que.push(point{ny,nx,curr.cost + 1, true});
                }
            } 
            else {
                visited[ny][nx][curr.skill == false ? 0 : 1] = true;
                que.push(point{ny,nx,curr.cost + 1, curr.skill});
            }
        }
    }
    return result;
}

void printMap() {
    int i,j;
    for(i = 0; i <= N+1; ++i) {
        for(j = 0; j <= M+1; ++j) {
            cout << table[i][j] << " "; 
        }
        cout << endl;
    }

}

int main() {
    init();
    // printMap();
    int result = bfs();

    cout << result << endl;

    return 0;
}