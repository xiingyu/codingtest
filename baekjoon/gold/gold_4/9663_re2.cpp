#include <iostream>
#include <vector>
using namespace std;

int N;
struct point {
    int y,x;
};

// int dx[] = {-1, -1, 1, 1, 0, -1, 0, 1};
// int dy[] = {-1, 1, -1, 1, -1, 0, 1, 0};

int dx[] = { -1, 1, -1, 0, 1};
int dy[] = {  1, 1, 0, 1, 0};

vector<vector<bool>> visited;
vector<point> results;

void printMap(const vector<vector<bool>> visited);

void init() {
    cin >> N;
    visited.assign(N, vector<bool>(N, false));
    // rowFlag.assign(N, false);

}

void clearAll(vector<vector<bool>>&visited, vector<bool>rowFlag) {
    visited.clear();    visited.assign(N, vector<bool>(N, false));
    rowFlag.clear();      rowFlag.assign(N, false);
}

void dfs(point curr, int cnt, vector<vector<bool>> visited, vector<bool> rowFlag) {
    int nx, ny, i,j;

    // cout << curr.y << " " << curr.x << " " << curr.cnt << endl;
    // printMap(curr.visited);
    visited[curr.y][curr.x] = true;

    if(cnt >= N) {
        results.push_back(curr);
        return;
    }


    // cross
    for(i = 0; i < 5; ++i) {
        nx = curr.x; ny = curr.y;
        while(true) {
            nx = nx + dx[i];
            ny = ny + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                visited[ny][nx] = true;
            } else {
                break;
            }
        }
    }
    
    // N Queen set
    ny = curr.y + 1;
    if(ny >= N) return;
    for(j = 0; j < N; ++j) {
        // if(i == curr.y && j <= curr.x) continue;
        if(visited[ny][j] == true || rowFlag[j] == true) continue;

        visited[ny][j] = true;
        rowFlag[j] = true;
        dfs(point{ny,j}, cnt + 1, visited, rowFlag);
        // cout << i << " " << j << " is pushed!!!!!!!!" << endl;
        visited[ny][j] = false;
        rowFlag[j] = false;
    }
    

}

void printMap(const vector<vector<bool>> visited) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(visited[i][j] == false) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }
}


int main() {
    vector<vector<bool>>visited;
    vector<bool>rowFlag;
    init();
    rowFlag.assign(N,false);
    for(int j = 0; j < N;++j) {
        clearAll(visited, rowFlag);
        dfs(point{0,j}, 1, visited, rowFlag);

    }

    cout << results.size() << endl;


    return 0;
}