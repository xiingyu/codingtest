#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> costs;
vector<vector<short>> table;

int maxEle = 0;
int maxCost = 0;
int maxDeepCity = 0;

bool init() {
    int a,b,c;
    vector<vector<int>> tempTable;
    while((cin >> a >> b >> c)) {
        tempTable.push_back({a, b, c}); 
        maxEle = max({a, b, maxEle});
    }
    
    visited.resize(maxEle + 1, false);
    table.resize(maxEle+1);
    costs.resize(maxEle+1);

    if(!tempTable.empty()) {
        for(int i = 0; i < tempTable.size(); ++i) {
            table[tempTable[i][0]].push_back(tempTable[i][1]);
            costs[tempTable[i][0]].push_back(tempTable[i][2]);
            table[tempTable[i][1]].push_back(tempTable[i][0]);
            costs[tempTable[i][1]].push_back(tempTable[i][2]);
        }
    } else {
        return false;
    }
    return true;
}

void clearAll() {
    visited.clear();    visited.resize(maxEle + 1, false);
    
    maxCost = 0;
}

void dfs(int currCity, int currCost) {
    // cout << " city : " << currCity << " cost : " << currCost<< endl;
    if(currCost > maxCost) {
        maxDeepCity = currCity;
        maxCost = currCost;
    }
    int next;
    for(int i = 0; i < table[currCity].size(); ++i) {
        next = table[currCity][i];
        if(visited[next])  continue;
        else {
            visited[next] = true;
            dfs(next, currCost + costs[currCity][i]);
            visited[next] = false;
        }
    }
}

void printMap() {
    for(int i = 0; i < costs.size(); ++i) {
        for(int j = 0; j < costs[i].size(); ++j) {
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    if(!init()) {
        return 0;
    }
    
    visited[1] = true;
    dfs(1,0);

    clearAll();
    
    visited[maxDeepCity] = true;
    dfs(maxDeepCity, 0);

    cout << maxCost << endl;

    return 0;
}