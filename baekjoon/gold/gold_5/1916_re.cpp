#include <iostream>
#include <queue>
#include <vector>
#define MAX 0x7FFFFFFF
using namespace std;

vector<vector<pair<int ,int>>> bus;       //cost, resize;
vector<int> distTable;
int N, M, start, goal;

void init() {
    int a,b,c;
    cin >> N >> M;

    bus.resize(N+1);
    distTable.resize(N+1, MAX);

    // cout << "start iter" << endl;
    for(int i = 0; i < M; ++i) {
        cin >> a >> b >> c;
        bus[a].push_back(make_pair(b,c));
    }
    cin >> start >> goal;
}

void dijkstra() {
    int nextNode, nextCost, currNode, currCost;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;

    que.push(make_pair(0, start));
    distTable[start] = 0;

    while(!que.empty()) {
        currCost = que.top().first;
        currNode = que.top().second;
        que.pop();

        
        if (distTable[currNode] < currCost) continue;

        for(int i = 0; i < bus[currNode].size(); ++i) {
            nextNode = bus[currNode][i].first;
            nextCost = bus[currNode][i].second;

            if(distTable[nextNode] > distTable[currNode] + nextCost) {
                distTable[nextNode] = distTable[currNode] + nextCost;
                // cout << "nextNode " << nextNode << " is pushed" << endl;
                que.push(make_pair(distTable[nextNode], nextNode));
            }
        }


    }
}


int main() {
    init();
    // cout << "end of init" << endl;
    dijkstra();
    cout << distTable[goal] << endl;
    return 0;

}