#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int n,m;
int flag = 0;

int is_all_visit(vector<int>& visited) {
    for (int curr : visited) {
        if (curr == false) return 0;
    }
    return 1;
}

void dfs(int curr, vector<int>& visited) {
    if (visited[curr] == true) return ;
    visited[curr] = true;
    int ans;

    for( int future : graph[curr]) {
        if (visited[future] == false) {
            visited[future] = true;
            // cout << " "<< future << " ";
            dfs(future, visited);

            
            ans = is_all_visit(visited);
            if (ans == 0) visited[future] = false;
            else if (ans == 1) {
                flag = 1; 
                return ;
            }

        }
    }

}

int main(void) {
    int temp_a, temp_b;
    int answer = 0;

    cin >> n >> m;
    vector<int> visited(n, false);
    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        cin >> temp_a >> temp_b;
        graph[temp_a].push_back(temp_b);
        graph[temp_b].push_back(temp_a);
    }

    for(int i = 0; i < n; ++i) {
        vector<int> visited(n, false);
        dfs(i, visited);
        if (flag == 1) {
            cout << 1 << endl;
            break;
        }
    }
    if (flag == 0) {
        cout << 0 << endl;
    }

}