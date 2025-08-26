#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1e9
using namespace std;

struct node {
    int s, e, cost;
};
int V,E,start;
vector<vector<node>> table;
vector<int> costTable;

auto cmp = [](const node&a, const node&b) {
    return a.cost > b.cost;
}
;
void init() {
    int s,e,c;
    cin >> V >> E >> start;

    table.resize(V+1);
    costTable.resize(V+1,MAX);

    while(E--) {
        cin >> s >> e >> c;
        table[s].push_back(node{s,e,c});
    }
    costTable[start] = 0;

}

void dijkstra() {
    priority_queue<node, vector<node>, decltype(cmp)> PQ(cmp);
    
    for(node curr : table[start]){
        costTable[curr.e] = min(costTable[curr.e], costTable[curr.s] + curr.cost);
        PQ.push(curr);
    }

    while(!PQ.empty()) {
        node curr = PQ.top();   PQ.pop();

        for(node next : table[curr.e]){
            if (costTable[next.e] > costTable[next.s] + next.cost) {
                costTable[next.e] = costTable[next.s] + next.cost;
                PQ.push(next);
            } 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    dijkstra();

    for(int i = 1; i <= V; ++i) {
        int cost = costTable[i];

        if(cost == MAX) {
            cout << "INF\n";
        } else {
            cout << cost << "\n";
        }
    }

    return 0;
}