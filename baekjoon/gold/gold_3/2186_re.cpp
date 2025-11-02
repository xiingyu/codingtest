#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N,M,K;
string target;
int targetSize = -1;
vector<vector<char>> table;
struct point {
    int y,x, nums;
};
vector<vector<vector<int>>> DP;

void init() {
    string temp;
    cin >> N >> M >> K;

    table.resize(N, vector<char>(M, 0));
    for(int i = 0; i < N; i++) {
        cin >> temp;
        for(int j = 0; j < M; ++j) {
            table[i][j] = temp[j];
        }
    }
    cin >> target;
    targetSize = (int)target.size() - 1;
    DP.resize(targetSize+1, vector<vector<int>>(N, vector<int>(M, 0)));
}

void findTarget() {
    int ny, nx;
    for(int i = 1; i <= targetSize; ++i) {
        int curr_num = i-1;
        for(int y = 0; y < N; ++y) {
            for(int x = 0; x < M; ++x) {
                if(DP[curr_num][y][x] != 0) {

                    for(int dxdy = 0; dxdy < 4; ++dxdy) {
                        for(int k = 1; k <= K; k++) {
                            ny = y + dy[dxdy]*k;
                            nx = x + dx[dxdy]*k;
                            
                            if(nx >= M || nx < 0 || ny >= N || ny < 0) continue;
                            if(table[ny][nx] == target[i]) DP[i][ny][nx] += DP[curr_num][y][x];
                            
                        }
                    }

                }
            }
        }

    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        
        for(int j = 0; j < M; ++j) {
            cout << DP[4][i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int result = 0;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == target[0]) DP[0][i][j] = 1;
        }
    }
    findTarget();
// printTable();
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            // if(DP[targetSize-1][i][j] != 0) cout << "findf!" << endl;
            result += DP[targetSize][i][j];
        }
    }
    cout << result;


    return 0;
}