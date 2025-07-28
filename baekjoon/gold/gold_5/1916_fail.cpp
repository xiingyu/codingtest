#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, start, goal;
vector<bool> visited;
vector<vector<int>> nexts,costs;
vector<int> takeCosts;
queue<int> que;

void init() {
    int i, s,e,c;
    cin >> N >> M;

    visited.resize(N+1, false); 
    takeCosts.resize(N+1, 0x7FFFFFFF);
    nexts.resize(N+1);  costs.resize(N+1);

    for(i = 0; i < M; ++i) {
        cin >> s >> e >> c;
        nexts[s].push_back(e);
        costs[s].push_back(c);
    }
    cin >> start >> goal;

    que.push(start);
    takeCosts[start] = 0;
    visited[start] = true;

}
void printCosts();

void dijkstra() {
    int curr, i, next, cost;

    while(!que.empty()) {

        curr = que.front(); que.pop();
        for(i = 0; i < nexts[curr].size(); ++i) {
            next = nexts[curr][i];
            cost = costs[curr][i];
            

            if (takeCosts[next] > takeCosts[curr] + cost) {
                takeCosts[next] = takeCosts[curr] + cost;
                que.push(next);
            }
            

        }
        
    }
}

void printCosts() {
    int i = 0;
    for(i = 0; i < takeCosts.size(); ++i) {
        cout << takeCosts[i] << " ";
    }
    cout << endl;
}

int main() {
    init();
    dijkstra();
    cout << takeCosts[goal] << endl;
    
}