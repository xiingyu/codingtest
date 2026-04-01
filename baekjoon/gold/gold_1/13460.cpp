#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N,M;
int takesTime = -1;
vector<vector<char>> table;

struct point {
    int y, x;
};
point R,B,O;

struct stage {
    int num;
    point R, B;
};


void init() {
    char temp;
    cin >> N >> M;
    table.resize(N, vector<char>(M));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> temp;
            if(temp == 'R' || temp == 'B' || temp == 'O') {
                if(temp == 'R')  R = point{i,j};
                else if(temp == 'B') B = point{i,j};
                else                O = point{i,j};

                table[i][j] = '.';
            }
            else {
                
                table[i][j] = temp;
            }
        }
    }
}

bool bfs() {
    stage nextStage;
    point nextR, nextB;
    int cntR, int cntB;

    queue<stage> q;
    q.push(stage{0, R, B});

    while(!q.empty()) {
        stage currStage = q.front();    q.pop();
        if(currStage.num > 10) return false;

        for(int i = 0; i < 4; ++i) {
            cntR = 0;   cntB = 0;
            while(true) {
                nextR = point{currStage.R.y + dy[i], currStage.R.x + dx[i]};
                if(nextR.y <= 0 || nextR.x <= 0 || nextR.y >= N-1 || nextR.x >= M-1)    break;

                cntR++;
            }
            while(true) {
                nextB = point{currStage.B.y + dy[i], currStage.B.x + dx[i]};
                if(nextB.y <= 0 || nextB.x <= 0 || nextB.y >= N-1 || nextB.x >= M-1)    break;
                cntB++;
            }
        }


    }

    return true;

}

int main() {

    return 0;
}