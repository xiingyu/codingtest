#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

vector<vector<int>> table;
// vector<vector<bool>> visited;

struct point {
    int y, x;
};


void init() {
    int temp;
    cin >> N >> M;
    table.resize(N, vector<int>(M, 0));
    // visited.resize(N, vector<bool>(M,false));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> temp;
            table[i][j] = temp;
        }
    }
}

int countZeros(const vector<vector<int>> &temp) {
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(temp[i][j] == 0)    cnt++;
        }
    }
    return cnt;
}

int simulate() {
    vector<vector<int>> temp = table;
    queue<point> que;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(temp[i][j] == 2) {
                que.push(point{i,j});
            } 
        }
    }

    // cout << que.size() << endl;

    while(!que.empty()) {
        point curr = que.front();   que.pop();

        for(int i = 0; i < 4; ++i) {
            point next;
            next.y = curr.y + dy[i];
            next.x = curr.x + dx[i];

            if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= M)  continue;
            if(temp[next.y][next.x] == 0){
                temp[next.y][next.x] = 2;
                que.push(next);
            }
        }


    }
    return countZeros(temp);
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int maximum = 0;
    int xs[] = {0,0,0};
    int ys[] = {0,0,0};

    init();
    for(int i = 0; i < N*M-2; ++i) {
        ys[0] = i / M;  xs[0] = i % M;
        if(table[ys[0]][xs[0]] != 0)    continue;

        for(int j = i+1; j < N*M-1; ++j) {
            ys[1] = j / M;  xs[1] = j % M;
            if(table[ys[1]][xs[1]] != 0)    continue;

            for(int k = j+1; k < N*M; ++k) {
                ys[2] = k / M;  xs[2] = k % M;
                if(table[ys[2]][xs[2]] != 0)    continue;
                
                // for(int ii = 0; ii < 3; ++ii) {
                //     cout << ys[ii] << xs[ii] << " ";
                // }
                // cout << endl;
                // cout << N << M;
                // cout << i << " " << j << " " << k << endl;


                for(int ii = 0; ii < 3; ++ii) {
                    table[ys[ii]][xs[ii]] = 3;
                }
                maximum = max(maximum, simulate());
                
                for(int ii = 0; ii < 3; ++ii) {
                    table[ys[ii]][xs[ii]] = 0;
                }
                

            }
        }
    }

    cout << maximum;

    return 0;
}