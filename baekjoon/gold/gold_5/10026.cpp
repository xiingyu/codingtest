#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int num = 0;

int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

vector<vector<bool>> visited;
vector<vector<char>> table;

struct point{
    int y,x;
};
queue<point> que;

void init() {
    string temp;
    cin >> N;
    table.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));

    for(int i = 0; i < N; ++i) {
        cin >> temp;
        for(int j = 0; j < N; ++j) {
            table[i][j] = temp[j];
        }
    }
}

void bfs(point current) {
    point next;
    char currColor = table[current.y][current.x];
    que.push(current);
    visited[current.y][current.x] = true;
    while(!que.empty()) {
        point curr = que.front();   que.pop();
        for(int i = 0; i < 4; ++i) {
            next.y = curr.y + dy[i];
            next.x = curr.x + dx[i];

            if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= N)  continue;
            if(visited[next.y][next.x]) continue;
            if(table[next.y][next.x] != currColor) continue;

            // cout << next.y << " " << next.x << endl;
            visited[next.y][next.x] = true;
            que.push(next);
        }
    }
}

int scanBound(bool colorDisorderFlag){
    int y, x;
    num = 0;
    visited.assign(N, vector<bool>(N, false));
    
    if(colorDisorderFlag){
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(table[i][j] == 'G') table[i][j] = 'R';
            }
        }

    } 

    for(int i = 0; i < N*N; ++i) {
        y = i / N;
        x = i % N;
        if(visited[y][x])   continue;
        num++;
        bfs(point{y,x});
        // cout << y << " " << x << endl;
    }

    return num;
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << visited[i][j] << " ";
        }
    cout << endl;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    cout << scanBound(false) << " " << scanBound(true);

    // printTable();
    return 0;
}