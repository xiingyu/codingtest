#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> table;
vector<vector<int>> results;

vector<vector<int>> dfs(int start, int depth) {
    int i, j;
    vector<vector<int>> re_temp;
    if (depth >= m) return re_temp;
    for(i = start; i <= n; ++i) {
        if(depth == 0) {
            vector<int> temp;
            temp.resize(m,i);
            results.push_back(temp);
        }
        else {
            results[results.size()-1][depth] = i;
        }
        dfs(start, depth +1);
    }   
}

void print_map() {
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    cin >> n >> m;
    results.resize(1, vector<int>(m,0));
    for(int i = 1; i <= n; ++i) {
        table.push_back(i);
    }
}