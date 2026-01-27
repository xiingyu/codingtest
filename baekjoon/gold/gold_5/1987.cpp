#include <iostream>
#include <vector>

using namespace std;

int R,C;
int maxCnt = 1;
int visited = 0;
vector<vector<int>> table;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct point {
    int y,x;
};

void init() {
    cin >> R >> C;

    table.resize(R, vector<int>(C,-1));

    string str;
    for(int i = 0; i < R; ++i) {
        cin >> str;

        for(int j = 0; j < C; ++j) {
            table[i][j] = (str[j] - 'A');
        }
    }

}

int DFS(point curr, int visit, int cnt) {
    point future;
    
    for(int i = 0; i < 4; ++i) {
        future.y = curr.y + dy[i];
        future.x = curr.x + dx[i];


        if(future.y < 0 || future.x < 0 || future.y >= R || future.x >= C) continue;
        if((visit >> table[future.y][future.x]) & 0x1) continue;

        

        visit |= 0x1 << table[future.y][future.x];
        maxCnt = max(DFS(future, visit,cnt + 1), maxCnt);
        
        visit &= ~(0x1 << table[future.y][future.x]);

    }
    
    return cnt;
}

void tablePrint() {
    for(int i = 0; i < R ; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int cnt = 1;
    init();
    
    visited |= 0x1 << table[0][0];
    DFS(point{0,0}, visited, cnt);
    cout << maxCnt;


    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

int R,C;
int maxCnt = 0;
vector<bool> visited;
vector<vector<int>> table;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct point {
    int y,x;
};

void init() {
    cin >> R >> C;

    table.resize(R, vector<int>(C,0));

    string str;
    for(int i = 0; i < R; ++i) {
        cin >> str;

        for(int j = 0; j < C; ++j) {
            table[i][j] = (str[j] - 'A' + 1);
        }
    }

    visited.resize(30, false);

}

int DFS(point curr, vector<bool> visit, int cnt) {
    point future;
    
    for(int i = 0; i < 4; ++i) {
        future.y = curr.y + dy[i];
        future.x = curr.x + dx[i];


        if(future.y < 0 || future.x < 0 || future.y >= R || future.x >= C) continue;
        if(visit[table[future.y][future.x]]) continue;

        // cout << future.y << " " << future.x  << " " << cnt << endl;

        visit[table[future.y][future.x]] = true;

        maxCnt = max(DFS(future, visit,cnt + 1), maxCnt);
        
        visit[table[future.y][future.x]] = false;

    }
    // cout << "one re completd" << endl;
    return cnt;
}

void tablePrint() {
    for(int i = 0; i < R ; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int cnt = 1;
    init();
    // tablePrint();
    visited[table[0][0]] = true;
    DFS(point{0,0}, visited, cnt);
    cout << maxCnt;


    return 0;
}
*/