#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, max_depth;
vector<int> waitArr;
vector<vector<int>> table;
queue<vector<int>> que;
int min_score = 0x0FFFFFFF;

void dfs(int start, int depth, vector<int> current) {
    if(depth>= max_depth) {
        que.push(current);
        return;
    }

    //1~N, included
    for(int i = start; i <= N; ++i) {
        current.push_back(i);
        dfs(i+1, depth+1, current);
        current.pop_back();
    }
}

bool is_in_vector(int target, vector<int> arr) {
    for(int i = 0; i < arr.size(); ++i) {
        if(target == arr[i]) return true;
    }
    return false;
}

int abs(int a, int b) {
    return a-b < 0 ? b-a : a-b;
}

void logic() {
    int aTeam, bTeam = 0;
    vector<int> aTeam_arr, bTeam_arr ;
    int i,a,b, a1, b1;
    while (!que.empty()) {
        vector<int> current = que.front();
        que.pop();

        aTeam_arr.clear(); bTeam_arr.clear();
        aTeam = 0;  bTeam = 0;

        for(i = 1; i <= N; ++i) {
            if(is_in_vector(i,current))
                aTeam_arr.push_back(i);
            else 
                bTeam_arr.push_back(i);
        }

        for(a = 0; a < aTeam_arr.size(); ++a) {
            for(a1 = a+1; a1 < aTeam_arr.size(); ++a1) {
                int x = aTeam_arr[a];
                int y = aTeam_arr[a1];
                aTeam += table[x][y] + table[y][x];
            }
        }
        
        for(b = 0; b < bTeam_arr.size(); ++b) {
            for(b1 = b+1; b1 < bTeam_arr.size(); ++b1) {
                int x = bTeam_arr[b];
                int y = bTeam_arr[b1];
                bTeam += table[x][y] + table[y][x];
            }
        }

        min_score = abs(aTeam - bTeam) < min_score ? abs(aTeam - bTeam) : min_score;

    }
}


void input() {
    int i,j;
    int intTmp;
    for(i = 1; i <= N; ++i) {
        for(j = 1; j <= N; ++j) {
            cin >> intTmp;
            table[i][j] = intTmp;
        }
    }
}


int main(void) {
    cin >> N;
    max_depth = (int)(N/2);
    table.resize(N+1, vector<int>(N+1,0));
    input();
    vector<int> temp;
    temp.clear();
    dfs(1,0,temp);
    logic();
    cout << min_score;

}