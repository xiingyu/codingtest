#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m,n;
int minCcnt= 0x7FFFFFFF;
vector<vector<int>> map;
vector<vector<bool>> visited;

int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,-1,1};

struct point{
    int y,x;
    vector<int> footprint;
};
queue<point> que;
vector<point> results;
point start,goal;

void input() {
    int i,j;
    int direction;
    cin >> m >> n;

    map.resize(m, vector<int>(n));
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    int y,x;
    cin >> y >> x >> direction;
    start = point{y-1,x-1, vector<int>(1,direction)};
    
    cin >> y >> x >> direction;
    goal = point{y-1,x-1, vector<int>(1,direction)};

}

void bfs() {
    int sx = start.x;
    int sy = start.y;

    que.push(point{start.y,start.x, start.footprint});
    visited[sy][sx] = true;
    while(!que.empty()) {
        point curr = que.front(); que.pop();
        if (curr.y == goal.y && curr.x == goal.x) {
            results.push_back(curr);
            continue;
        }

        for(int i = 1; i <= 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
                visited[ny][nx] == false && map[ny][nx] == 0) {

                visited[ny][nx] = true;
                curr.footprint.push_back(i);
                que.push(point{ny,nx,curr.footprint});
                curr.footprint.pop_back();

                }
        }
    }
}

void findMin(int befCmd) {
    int i;
    int continueCmd = 1;
    int ccnt = 0;

    for(auto& result : results) {
        ccnt = 0;
        for(i = 0; i < result.footprint.size(); ++i ) {
            cout << "befCmd : " << befCmd ;
            int curCmd = result.footprint[i];
            if(curCmd != befCmd) {
                if((curCmd == 2 && befCmd == 3)||(curCmd == 3 && befCmd == 2)) {
                    ccnt += 2;
                }
                else if(abs(curCmd - befCmd) == 1) 
                    ccnt += 3;
                else {
                    ccnt += 2;
                }
                continueCmd = 1;
                befCmd = curCmd;
            }
            else {
                // cout <<endl<< "continueCmd : " << continueCmd << endl;
                // if (continueCmd == 1) ccnt +=1;
                if(continueCmd >= 3) {
                    continueCmd = 1;
                    ccnt += 1;
                }
                else {
                    continueCmd++;
                }

            }
            if (i == result.footprint.size()-1) {
                // cout << endl << "last pang curCmd : " << curCmd << "  ccnt : " << ccnt << endl;
                if(curCmd != goal.footprint[0]) {

                    
                if((curCmd == 2 && goal.footprint[0] == 3)||(curCmd == 3 && goal.footprint[0] == 2)) {
                    ccnt += 1;
                    }
                else if(abs(curCmd - goal.footprint[0]) == 1) 
                    ccnt += 2;
                else {
                    ccnt += 1;
                    }
                // cout << endl << "last pang curCmd : " << curCmd << "  ccnt : " << ccnt << endl;
                }
                // else {
                //     if (continueCmd == 1) ccnt +=1;
                // }
            }
            cout << "  curCmd : " << curCmd << "  ccnt : " << ccnt << endl;
        }
        minCcnt = min(minCcnt, ccnt);
    }

}

void printMap() {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    input();
    visited.resize(m, vector<bool>(n,false));
    bfs();
    findMin(start.footprint[0]);
    // printMap();
    cout << minCcnt<<endl;
    

}