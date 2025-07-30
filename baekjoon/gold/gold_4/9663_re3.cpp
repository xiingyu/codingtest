#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
struct point {
    int y,x;
};

vector<vector<bool>> visited;
vector<bool> colFlag;
vector<point> sellected;

int results = 0;

void printMap(const vector<vector<bool>> visited);

void init() {
    cin >> N;
    visited.assign(N, vector<bool>(N, false));
    // colFlag.assign(N, false);

}

void clearAll() {
    visited.clear();    visited.assign(N, vector<bool>(N, false));
    colFlag.clear();      colFlag.assign(N, false);  
    
}

void dfs(point curr) {
    int nx, ny, i,j;
    bool reFlag = true;

    if(sellected.size() >= N) {
        results++;
        return;
    }
    // cout << curr.y << " " << curr.x << endl;
    ny = curr.y + 1;
    if(ny >= N) return;
    // nx ny set
    for(i = 0; i < N; ++i) {
        nx = i;
        if(colFlag[i] == true)  continue;

        reFlag = true;
        for(point next : sellected) {
            if(abs(nx-next.x) == abs(ny-next.y)) {
                reFlag = false;
                break;
            }

        }
        if (reFlag) {
            visited[ny][nx] = true;
            colFlag[nx] = true;
            sellected.push_back(point{ny,nx});
            // cout << "dfs start" << endl;
            dfs(point{ny,nx});

            sellected.pop_back();
            visited[ny][nx] = false;
            colFlag[nx] = false;
        }
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
    
    init();
    for(int j = 0; j < N;++j) {
        clearAll();
        visited[0][j] = true;
        colFlag[j] = true;
        sellected.push_back(point{0,j});

        dfs(point{0,j});

        visited[0][j] = false;
        colFlag[j] = false;
        sellected.pop_back();

    }

    cout << results << endl;


    return 0;
}