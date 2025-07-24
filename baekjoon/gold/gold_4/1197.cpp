#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V, E;
vector<int> 
    MST,
    parent;

struct node{
    int start,end,cost;
};
vector<node> nodes;

void init() {
    int s,e,c, i;
    cin >> V >> E;

    parent.resize(V+1);
    for(i = 1; i <= V; ++i) parent[i] = i;

    for(i = 1; i <= E; ++i) {
        cin >> s >> e >> c;
        nodes.push_back(node{s,e,c});
    }
    sort(nodes.begin(), nodes.end(), [](const node& a, const node& b) {
        return (a.cost < b.cost);
    });
    
}

int getParent(int a) {
    if (parent[a] != a)
        parent[a] = getParent(parent[a]); 
    return parent[a];
}

// void setParent(int a, int b) {
//     if(a != b) parent[b] = a;
// }

int logicMST() {
    int i;
    int totalCost = 0;

    for(i = 0; i < nodes.size(); ++i) {
        node curr = nodes[i];

        int startParent = getParent(curr.start);
        int endParent = getParent(curr.end);
        
        if(startParent == endParent) continue;
        else {
            // setParent(startParent, endParent);
            if(startParent != endParent) parent[endParent] = startParent;
            MST.push_back(i);
            totalCost += nodes[i].cost;

            if(MST.size() >= V-1) return totalCost;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int totalCost = 0;
    init();
    totalCost = logicMST();

    cout << totalCost << endl;

}