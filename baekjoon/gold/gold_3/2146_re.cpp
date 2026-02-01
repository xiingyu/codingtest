#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int landNums = 0;
int minimum = 1e9;

int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

vector<vector<int>> table;
vector<vector<bool>> visited;

struct point {
    int y, x;
};
vector<vector<point>> lands;

void init() {
    int temp;
    cin >> N;
    table.resize(N, vector<int>(N,0));
    visited.resize(N, vector<bool>(N, false));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> temp;
            if(temp == 1) table[i][j] = -1;
            else table[i][j] = 0;
        }
    }
}

void makeVisit(point region) {
    vector<point> tempVector;
    queue<point> que;
    que.push(region);       
    // tempVector.push_back(region);

    while(!que.empty()) {
        point curr = que.front();   que.pop();
        table[curr.y][curr.x] = landNums;
        int wallFlag = 0;

        for(int i = 0; i < 4; ++i) {
            point next;
            next.y = curr.y + dy[i];    next.x = curr.x + dx[i];

            if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue;
            if(table[next.y][next.x] == 0)  wallFlag++;
            if(table[next.y][next.x] != -1) continue;
            if(visited[next.y][next.x]) continue;

            que.push(next); 
            // tempVector.push_back(next);
            visited[next.y][next.x] = true;
            table[next.y][next.x] = landNums;
            if(wallFlag == 4)   tempVector.push_back(next);
        }
        
    }
    lands.push_back(tempVector);

}

void findLand() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(visited[i][j])   continue;
            visited[i][j] = true;

            if(table[i][j] == -1) {
                landNums++;
                makeVisit(point{i,j});
            }
        }
    }

}

int BFS(const point &region) {
    // cout << "called" << endl;
    // int distance = 1e9;
    queue<point> que;
    visited.assign(N, vector<bool>(N, false));
    que.push(region);   visited[region.y][region.x] = true;

    while(!que.empty()) {
        point curr = que.front();   que.pop();

        for(int i = 0; i < 4; ++i) {
            point next;
            next.y = curr.y + dy[i];    next.x = curr.x + dx[i];
            if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= N) continue;
            if(visited[next.y][next.x]) continue;
            // distance = abs(next.y - region.y) + abs(next.x - region.x);
            // if(distance > minimum)  continue;

            if((table[next.y][next.x] != 0) && (table[next.y][next.x] != table[region.y][region.x])) return abs(next.y - region.y) + abs(next.x - region.x) - 1;

            que.push(next);
            visited[next.y][next.x] = true;
        }

    }

    return 1e9;
}



void findRoute() {
    for(int i = 0; i < (int)lands.size(); ++i) {
        for(int j = 0; j < (int)lands[i].size(); ++j ) {
            point curr = lands[i][j];

            minimum = min(minimum, BFS(curr));
        }
    }

}


void printTable() {
    cout << lands.size() << " " << lands[0].size() << endl;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    findLand();
    // printTable();
    findRoute();

    cout << minimum;

    return 0;
}