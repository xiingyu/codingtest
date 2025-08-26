#include <iostream>
#include <vector>
#include <queue>
#define MAX 1e9
using namespace std;

int V,E, start;
struct node {
    int s, e, cost;
};
vector<vector<node>> table;
vector<int> costTable;
vector<bool> visited;

auto cmp = [](const node&a, const node&b) {
    return a.cost > b.cost;
};

void init() {
    int u,v,w;
    cin >> V >> E >> start;

    table.resize(V+1);
    visited.resize(V+1,false);
    costTable.resize(V+1, MAX);

    for(int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        table[u].push_back(node{u,v,w});
    }
}


int dijkstra(int goal) {
    priority_queue<node, vector<node>, decltype(cmp)> PQ(cmp);
    visited.clear();    visited.resize(V+1,false);
    costTable.clear();  costTable.resize(V+1, MAX);

    costTable[start] = 0;
    visited[start] = true;

    for(node i : table[start]) {
        visited[i.e] = true;
        costTable[i.e] = costTable[start] + i.cost;
        PQ.push(i);
    }

    while(!PQ.empty()) {
        node curr = PQ.top();   PQ.pop();

        if(curr.e == goal) {
            costTable[curr.e] = costTable[curr.s] + curr.cost;
            break;
        }

        for(node next : table[curr.e]) {
            if(!visited[next.e]) {
                visited[next.e] = true;
                costTable[next.e] = costTable[next.s] + next.cost;
                PQ.push(next);
            }
        }

    }

    return costTable[goal];
}

void debug() {
    cout << dijkstra(4) << endl;

    exit(0);
}

int main() {
    init();

    int costs;

    // debug();

    for(int i = 1; i <= V; ++i) {
        if(i == start) {
            cout << 0 << "\n";
        }
        else {
            costs = dijkstra(i);
            if(costs == MAX) cout << "INF\n";
            else             cout << costs << "\n";
        }
    }
    

    return 0;
}