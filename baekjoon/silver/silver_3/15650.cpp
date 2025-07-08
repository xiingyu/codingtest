#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int>> results;

void dfs(int start, int depth, vector<int> current) {
    int i, j;
    if (depth >= m) {
        results.push_back(current);
        return ;
    }
    for(i = start; i <= n; ++i) {
        current.push_back(i);
        dfs(i+1, depth+1, current);
        current.pop_back();
    }

}

void print_map() {
    for(int i = 1; i < results.size(); ++i) {
        for(int j = 0; j < m; ++j) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    cin >> n >> m;
    results.resize(1, vector<int>(m,0));
    vector<int> empty_vector;
    dfs(1,0,empty_vector);
    print_map();
}