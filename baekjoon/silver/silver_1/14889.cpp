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
        que.push(current);
        return;
    }

    //1~N, included
    for(int i = start; i <= N; ++i) {
        current.push_back(i);
        dfs(i+1, depth, current);
        current.pop_back();
    }
}

bool is_in_vector(int target, vector<int> arr) {
    for(int i = 0; i < arr.size(); ++i) {
        if(target == arr[i]) return true;
    }
    return false;
}

void logic() {
    int aTeam, bTeam;
    int i;
    while (!que.empty()) {
        vector<int> current = que.front();
        que.pop();

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
    max_depth = (int)(N/2 -1);
    table.resize(N, vector<int>(N,0));
    input();

}