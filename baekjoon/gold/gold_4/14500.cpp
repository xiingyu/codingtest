#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximum = -1;
int N,M;
struct dd {
    int dy,dx;
};
vector<vector<vector<dd>>> types;
vector<vector<int>> table;

void init() {
    cin >> N >> M;
    table.resize(N,vector<int>(M));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> table[i][j];
        }
    }
    /*
    types
    0 : -
    1 : square
    2 : L
    3 : z
    4 : fuck
    */
   types.resize(5);
   types[0].resize(2);  types[1].resize(1); types[2].resize(8); types[3].resize(4); types[4].resize(4);
   types[0][0].push_back(dd{0,1});types[0][0].push_back(dd{0,2});types[0][0].push_back(dd{0,3});
   types[0][1].push_back(dd{1,0});types[0][1].push_back(dd{2,0});types[0][1].push_back(dd{3,0});

   types[1][0].push_back(dd{1,0});types[1][0].push_back(dd{0,1});types[1][0].push_back(dd{1,1});
   
   types[2][0].push_back(dd{1,0});types[2][0].push_back(dd{2,0});types[2][0].push_back(dd{2,1});
   types[2][1].push_back(dd{1,0});types[2][1].push_back(dd{0,1});types[2][1].push_back(dd{0,2});
   types[2][2].push_back(dd{0,1});types[2][2].push_back(dd{1,1});types[2][2].push_back(dd{2,1});
   types[2][3].push_back(dd{0,1});types[2][3].push_back(dd{0,2});types[2][3].push_back(dd{-1,2});
   types[2][4].push_back(dd{1,0});types[2][4].push_back(dd{2,0});types[2][4].push_back(dd{2,-1});
   types[2][5].push_back(dd{1,0});types[2][5].push_back(dd{1,1});types[2][5].push_back(dd{1,2});
   types[2][6].push_back(dd{0,1});types[2][6].push_back(dd{1,0});types[2][6].push_back(dd{2,0});
   types[2][7].push_back(dd{0,1});types[2][7].push_back(dd{0,2});types[2][7].push_back(dd{1,2});

   types[3][0].push_back(dd{1,0});types[3][0].push_back(dd{1,1});types[3][0].push_back(dd{2,1});
   types[3][1].push_back(dd{0,1});types[3][1].push_back(dd{-1,1});types[3][1].push_back(dd{-1,2});
   types[3][2].push_back(dd{1,0});types[3][2].push_back(dd{1,-1});types[3][2].push_back(dd{2,-1});
   types[3][3].push_back(dd{0,1});types[3][3].push_back(dd{1,1});types[3][3].push_back(dd{1,2});

   
   types[4][0].push_back(dd{0,1});types[4][0].push_back(dd{0,-1});types[4][0].push_back(dd{1,0});
   types[4][1].push_back(dd{1,0});types[4][1].push_back(dd{-1,0});types[4][1].push_back(dd{0,-1});
   types[4][2].push_back(dd{-1,0});types[4][2].push_back(dd{0,1});types[4][2].push_back(dd{0,-1});
   types[4][3].push_back(dd{0,1});types[4][3].push_back(dd{1,0});types[4][3].push_back(dd{-1,0});
}

void counting(vector<dd> shape) {
    dd nxt;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            int cnt = 0;    bool flag = true;
            dd curr = dd{i,j};
            cnt += table[i][j];
            for(dd d : shape) {
                nxt.dy = curr.dy + d.dy;
                nxt.dx = curr.dx + d.dx;
                if(nxt.dy < 0 || nxt.dx < 0 || nxt.dy >= N || nxt.dx >= M) {
                    flag = false;
                    break;
                }
                cnt += table[nxt.dy][nxt.dx];
            }

            if(flag) maximum = max(maximum, cnt);

        }
    }
}

void logic(){
    for(int i = 0; i < (int)types.size(); ++i) {
        for(int j = 0; j < (int)types[i].size(); ++j) {
            counting(types[i][j]);
        }
    }

}



int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    init();
    logic();


    cout << maximum;

    return 0;
}