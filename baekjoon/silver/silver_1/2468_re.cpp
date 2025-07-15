#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, maxEle, minEle;
int result = 0;
vector<vector<bool>> visited;
vector<vector<int>> map;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct point {
    int y,x;
};
queue<point> que;

void input() {
    int i,j;
    
    map.resize(n, vector<int>(n,0));
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    int maxTemp = 0;
    int minTemp = 0x7FFFFFFF;
    for(const auto& row : map) {
        maxTemp = max(maxTemp, *max_element(row.begin(), row.end()));
        minTemp = min(minTemp, *min_element(row.begin(), row.end()));
    }
    maxEle = maxTemp;
    minEle = minTemp;
}

void bfs(int unsafe) {
    while(!que.empty()) {
        point cur = que.front(); que.pop();

        for(int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx >=0 && ny >= 0 && nx < n && ny < n && visited[ny][nx] == false && map[ny][nx] > unsafe) {
                visited[ny][nx] = true;
                que.push(point{ny,nx});
            }
        }
    }
}

void logic(int unsafe) {
    int i,j;
    int cnt = 0;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            if(map[i][j] > unsafe && visited[i][j] == false) {
                visited[i][j] = true;
                que.push(point{i,j});
                bfs(unsafe);
                ++cnt;
            }
        }
    }
    result = max(result, cnt);
}

int main(){ 
    cin >> n;
    visited.resize(n, vector<bool>(n,false));
    input();
    for(int i = minEle-1; i <= maxEle; ++i) {
        visited.assign(n, vector<bool>(n,false));
        logic(i);
    }
    cout << result;

}