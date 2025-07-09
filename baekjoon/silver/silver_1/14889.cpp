#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, max_depth;
vector<int> waitArr;
vector<vector<int>> table;
queue<vector<int>> que;

void dfs(int start, int depth, vector<int> current) {
    if(depth>= max_depth) {
        
    }
}



void input() {
    int i,j;
    int intTmp;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            cin >> intTmp;
            table[i][j] = intTmp;
        }
    }
}


int main(void) {
    cin >> N;
    table.resize(N, vector<int>(N,0));
    input();

}