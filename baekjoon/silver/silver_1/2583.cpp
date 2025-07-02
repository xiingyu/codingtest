#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> bfill;
vector<int> results;

int n,m,k;

struct bbox {
    int sx;
    int sy;
    int ex;
    int ey;
};
vector<bbox> lists;

struct point {
    int x,y;
};
queue<point> que;

void printmap() {
    for(int y = 0; y < m; ++y) {
        for(int x = 0; x < n; ++x) {
            if (bfill[y][x])
                cout << 1 << " ";
            else 
                cout << 0 << " ";
        }
        cout <<endl;
    }
}

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void initialize() {
    bfill.resize(m, vector<bool>(n, false));
}

void input() {

    for(int i=0; i < k; ++i) {
        bbox temp;
        cin >> temp.sx >> temp.sy >> temp.ex >> temp.ey;
        lists.push_back(temp);
    }

    for(bbox target : lists) {
        for(int y = target.sy; y < target.ey; ++y) {
            for(int x = target.sx; x < target.ex; ++x) {
                bfill[y][x] = true;
            }
        }
    }
}

int bfs() {
    int cnt = 1;

    while(!que.empty()) {
        point current = que.front();
        que.pop();
        int cx = current.x, cy = current.y;
        int nx,ny;

        for(int i = 0; i < 4; ++i) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if((nx < 0 || ny < 0 || nx >= n || ny >= m) || (bfill[ny][nx] == true)) {
                continue;
            }
            bfill[ny][nx] = true;
            que.push(point{nx,ny});
            cnt++;
        }
    }
    return cnt;
}


void search() {

    for(int y = 0; y < m; ++y) {
        for(int x = 0; x < n; ++x) {
            if(bfill[y][x] == false) {
                bfill[y][x] = true;
                que.push(point{x,y});
                results.push_back(bfs());
            }
        }
    }
    
}



int main(void) {
    cin >> m >> n >> k;
    initialize();
    input();
    search();
    cout << results.size() << endl;
    sort(results.begin(),results.end());
    for(int i = 0; i < results.size(); ++i) {
        cout << results[i] << " ";
    }

}