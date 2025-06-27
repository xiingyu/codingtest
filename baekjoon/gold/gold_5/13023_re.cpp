#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int n,m;
bool flag = false;

void dfs(int curr, int depth) {
    // cout << "curr : " << curr << endl;
    if (flag) return ;
    
    if (depth == 5) {
        flag = true;
        return ;
    }
    visited[curr] = true;

    for( int future : graph[curr]) {
        if (visited[future] == false) {
            dfs(future, depth+1);

        }
    }
    visited[curr] = false;
}

int main(void) {
    int temp_a, temp_b;
    int answer = 0;

    cin >> n >> m;
    visited.resize(n,false);
    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        cin >> temp_a >> temp_b;
        graph[temp_a].push_back(temp_b);
        graph[temp_b].push_back(temp_a);
    }

    for(int i = 0; i < n; ++i) {
        fill(visited.begin(), visited.end(), false);
        dfs(i, 1);
        if (flag == true) {
            cout << 1 << endl;
            break;
        }
    }
    if (flag == false) {
        cout << 0 << endl;
    }

}