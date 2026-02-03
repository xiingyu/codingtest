#include <iostream>
#include <vector>
#include <queue>
#define MAX 1e9
using namespace std;

int N,K;
int dx[] = {-1, 1};
vector<int> costTable;
struct point {
    int cost, region;
};

void init() {
    cin >> N >> K;
    costTable.resize(100001, MAX);
}

int BFS() {
    int cost = 0;
    int curr = N;
    queue<point> que;   que.push(point{0,N});   costTable[N] = 0;

    while(!que.empty()) {
        point curr = que.front();   que.pop();
        if( curr.region == K)   return curr.cost;

        for(int i = 0; i < 3; ++i){
            point next;
            next.cost = curr.cost + 1;
            if(i == 2) {
                next.region = curr.region * 2;
            } else {
                next.region = curr.region + dx[i];
                
            }
            if(next.region < 0 || next.region > 100000) continue;
            if(next.cost >= costTable[next.region])  continue;
            costTable[next.region] = next.cost;
            que.push(next);
        }
    }
    return cost;
}

int main() {
    init();
    int answer = BFS();
    cout << answer;

    return 0;
}