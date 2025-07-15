#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int maxDist = 0;
int w,h;
vector<vector<int>> map;
vector<vector<bool>> visited;

struct point{
    int y,x;
};
struct bfsPoint {
    int y,x,dist;
};

queue<point> targets;
queue<bfsPoint> que;
vector<vector<point>> lands;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void findLength();

void input() {
    cin >> h >> w;
    map.resize(h, vector<int>(w));
    // lands.resize(h, vector<int>(w,0));
    visited.resize(h, vector<bool>(w, false));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            char temp;
            cin >> temp;
            if (temp == 'L') {
                map[i][j] = 1;
            }
        }
    }

}

void findLand() {
    int i,j;
    for(i = 0; i < h; ++i) {
        for(j = 0; j < w; ++j) {
            if(map[i][j] == 1 && visited[i][j] == false) {
                visited[i][j] == true;
                targets.push(point{i,j});
                findLength();
            }
        }
    }
}

void findLength() {
    vector<point> land;
    while(!targets.empty()) {
        point current = targets.front(); targets.pop();
        for(int i = 0; i < 4; ++i) {
            int futurex = current.x + dx[i];
            int futurey = current.y + dy[i];

            if((futurex >=0 && futurey >= 0 && futurex < w && futurey < h)
                && map[futurey][futurex] == 1 && visited[futurey][futurex] == false) {
                targets.push(point{futurey,futurex});
                land.push_back(point{futurey,futurex});
                visited[futurey][futurex] = true;
            }
        }
    }
    lands.push_back(land);
}

void bfs(point curr) {
    int dist = 0;
    que.push(bfsPoint{curr.y,curr.x,0});
    visited.assign(h, vector<bool>(w, false));
    while(!que.empty()) {
        bfsPoint current = que.front(); que.pop();
        visited[current.y][current.x] = true;
        for(int i=0; i < 4; ++i) {
            int futurex = current.x + dx[i];
            int futurey = current.y + dy[i];
            if((futurex >=0 && futurey >= 0 && futurex < w && futurey < h)
                && map[futurey][futurex] == 1 && visited[futurey][futurex] == false) {
    // cout << curr.y << " " << curr.x << endl;
                    visited[futurey][futurex] = true;
                    que.push(bfsPoint{futurey,futurex, current.dist+1});

            }
        }
        maxDist = max(current.dist, maxDist);
    }


}

void logic() {
    for(int i = 0; i < lands.size(); ++i) {
        for(int j =0; j < lands[i].size(); ++j) {
            bfs(lands[i][j]);
        }

    }
}

void printMap() {
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < lands.size(); ++i) {
        for(int j = 0; j < lands[i].size(); ++j) {
            cout << lands[i][j].y << " " << lands[i][j].x;
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}


int main() {
    input();
    findLand();
    // printMap();
    logic();
    cout << maxDist;


}