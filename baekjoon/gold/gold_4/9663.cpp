#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
struct point {
    int y,x, cnt;
    vector<vector<bool>>visited;
};

int dx[] = {-1, -1, 1, 1, 0, -1, 0, 1};
int dy[] = {-1, 1, -1, 1, -1, 0, 1, 0};

vector<vector<int>> table;
vector<point> results;
queue<point> que;


void printMap(const vector<vector<bool>> visited);

void init() {
    cin >> N;
    table.assign(N, vector<int>(N, 0));

}

void clearAll(vector<vector<bool>>&visited) {
    visited.clear();    visited.assign(N, vector<bool>(N, false));
    table.clear();      table.assign(N, vector<int>(N, 0));
}

void bfs(point start) {
    int nx, ny, i,j;
    que.push(start);

    while(!que.empty()) {
        point curr = que.front();   que.pop();
        // cout << curr.y << " " << curr.x << " " << curr.cnt << endl;
        // printMap(curr.visited);
        curr.visited[curr.y][curr.x] = true;

        if(curr.cnt >= N) {
            results.push_back(curr);
            continue;
        }


        // cross
        for(i = 0; i < 8; ++i) {
            nx = curr.x; ny = curr.y;
            while(true) {
                nx = nx + dx[i];
                ny = ny + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    curr.visited[ny][nx] = true;
                } else {
                    break;
                }
            }
        }
        
        // // around
        // for(i = 4; i < 8; ++i) {
        //     nx = curr.x + dx[i];
        //     ny = curr.y + dy[i];

        //     if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
        //         visited[ny][nx] = true;
        //     }
            
        // }

        // cout << endl;
        // printMap(curr.visited);
        // N Queen set
        for(i = curr.y; i < N; ++i) {
            for(j = 0; j < N; ++j) {
                if(i == curr.y && j <= curr.x) continue;
                if(curr.visited[i][j] == true) continue;

                curr.visited[i][j] = true;
                que.push(point{i,j, curr.cnt + 1, curr.visited});
                // cout << i << " " << j << " is pushed!!!!!!!!" << endl;
                curr.visited[i][j] = false;
            }
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
    vector<vector<bool>>visited;
    init();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N;++j) {
            clearAll(visited);
            bfs(point{i,j, 1, visited});

        }
    }

    cout << results.size() << endl;


    return 0;
}