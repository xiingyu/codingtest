#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,v;
vector<int> dfs_history;
vector<int> bfs_history;

int graph[1000+1][1000+1];
int visited_dfs[1000+1] = {false,};
int visited_bfs[1000+1] = {false,};
queue<int> que;


void dfs(int start) {
    if (visited_dfs[start] == true) {
        return ;
    }
    visited_dfs[start] = true;
    dfs_history.push_back(start);

    for (int future = 1; future <= n; ++future) {
        if((graph[start][future] == 1) && visited_dfs[future]==false) {
            dfs(future);
        }
    }


}

void bfs(int start) {
    que.push(start);
    visited_bfs[start] = true;
    // bfs_history.push_back(start);


    while (!que.empty()) {
        int curr = que.front();
        que.pop();
        // if (visited_bfs[curr] == true) {
        //     continue;
        // }
        bfs_history.push_back(curr);

        
        for (int future = 1; future <= n; ++future) {
            if((graph[curr][future] == 1) && visited_bfs[future]==false) {
                que.push(future);
                visited_bfs[future] = true;
            }
        }

    }


}


int main(void) {
    int i, temp_a, temp_b;
    cin >> n >> m >> v;
    
    for(i = 0; i < m; ++i) {
        cin >> temp_a >> temp_b;
        graph[temp_a][temp_b] = 1;
        graph[temp_b][temp_a] = 1;

    }


    dfs(v);
    for(i = 0; i< dfs_history.size(); ++i) {
        cout << dfs_history[i] << " ";
    }
    cout << endl;


    bfs(v);
    for(i = 0; i< dfs_history.size(); ++i) {
        cout << bfs_history[i] << " ";
    }
    cout << endl;


}