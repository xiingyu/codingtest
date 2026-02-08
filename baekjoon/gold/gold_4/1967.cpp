#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1e9
using namespace std;

int maxi = -1;
int N;
int anotherLeaf;

struct node {
    int num,cost;
};
vector<vector<node>> table;
vector<int> costTable;
vector<bool> visited;

queue<int> targetLeafs;

void init() {
    int a,b,c;
    cin >> N;
    table.resize(N+1);
    costTable.resize(N+1, 0);
    visited.resize(N+1, false);

    for(int i = 0; i < N-1; ++i) {
        cin >> a >> b >> c;
        table[a].push_back(node{b,c});
        table[b].push_back(node{a,c});
    }
}

void findLeaf() {
    queue<node> que;
    visited[1] = true;
    for(int i = 0; i < (int)table[1].size(); ++i) {
        que.push(table[1][i]);
        visited[table[1][i].num] = true;
        costTable[table[1][i].num] = table[1][i].cost;
    }

    while(!que.empty()) {
        node curr = que.front();    que.pop();

        for(node next : table[curr.num]) {
            if(visited[next.num])   continue;
            costTable[next.num] = costTable[curr.num] + next.cost;
            visited[next.num] = true;
            que.push(next);
        }
    }

    int candidate = *max_element(costTable.begin(), costTable.end());
    for(int i = 0; i < N+1; ++i) {
        if(costTable[i] == candidate) {
            // cout << "maxele : " << i << " " << costTable[i] << endl;
            targetLeafs.push(i);
        }
    }
}

void printTable() {
    for(int i = 0; i < (int)costTable.size(); ++i) {
        cout << costTable[i] << " " ;
    }
}

void findAnotherLeaf() {
    while(!targetLeafs.empty()) {
        int candidate = targetLeafs.front();   targetLeafs.pop();
        queue<node> que;
        visited.assign(N+1, false); costTable.assign(N+1, 0);
        visited[candidate] = true;

        for(int i = 0; i < (int)table[candidate].size(); ++i) {
            que.push(table[candidate][i]);
            visited[table[candidate][i].num] = true;
            costTable[table[candidate][i].num] = table[candidate][i].cost;
        }

        while(!que.empty()) {
            node curr = que.front();    que.pop();

            for(node next : table[curr.num]) {
                if(visited[next.num])   continue;
                costTable[next.num] = costTable[curr.num] + next.cost;
                visited[next.num] = true;
                que.push(next);
            }
        }

        maxi = max(maxi, *max_element(costTable.begin(), costTable.end()));
        
        // for(int i = 0; i < N+1; ++i) {
        //     if(costTable[i] == *max_element(costTable.begin(), costTable.end())) {
        //         cout << "maxele : " << i << " " << costTable[i] << endl;
        //     }
        // }
        // printTable();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    findLeaf();
    // printTable();
    findAnotherLeaf();

    cout << maxi;

    return 0;
}