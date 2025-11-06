#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int V,E;
struct node {
    int start, end, cost;
};
vector<node> nodes;
vector<int> parents;

auto cmp(const node& a, const node& b) {
    return a.cost < b.cost;
}

int findParent(int target) {
    if(parents[target] == target) return target;
    return parents[target] = findParent(parents[target]);

}

void assignParent(int target, int targetParent) {
    parents[findParent(target)] = findParent(targetParent);
}

void init() {
    cin >> V >> E;

    parents.resize(V+1);
    for(int i = 0; i <= V; ++i) {
        parents[i] = i;
    }

    for(int i = 0; i < E; ++i) {
        int s,e,c;
        cin >> s >> e >> c;
        nodes.push_back(node{s,e,c});
    }

    sort(nodes.begin(), nodes.end(), cmp);

}

int logicMST() {
    int cost = 0;
    int vertex = 0;
    for(node target : nodes) {
        // printParents();
        if( vertex >= V-1) break;
        int stParent = findParent(target.start);
        int edParent = findParent(target.end);

        if(stParent != edParent) {
            assignParent(target.end, target.start);
            cost += target.cost;
            vertex++;
        }
        else {
            continue;
        }
    }
    return cost;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    cout << logicMST();

    return 0;
}