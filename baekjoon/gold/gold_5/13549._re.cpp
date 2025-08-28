#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;

int N, K;
int result = 0;
int dx[] = {-1, 1};
vector<bool> visited;
struct point {
    int x, time;
};
auto cmp = [](const point& a, const point& b) {
    return a.time > b.time;
};

void init() {
    cin >> N >> K;
    visited.resize(MAX+1, false);
}

void dijkstra() {
    int nx;
    priority_queue<point, vector<point>, decltype(cmp)> PQ(cmp);
    PQ.push(point{N, 0});
    // visited[N] = true;

    while(!PQ.empty()) {
        // point curr = PQ.top(); PQ.pop();
        // cout << "curr.x : " << curr.x << endl;

        // if(curr.x == K) {
        //     result = curr.time;
        //     return;
        // }

        
        // nx = curr.x * 2;
        // if(nx <= MAX && !visited[nx]){
        //     visited[nx] = true;
        //     PQ.push(point{nx, curr.time});
        // }
       
            

        // for(int i = 0; i < 2; ++i) {
        //     nx = curr.x + dx[i];

        //     if(nx < 0 || nx > MAX || visited[nx]) continue;

        //     visited[nx] = true;
        //     PQ.push(point{nx, curr.time + 1});
        // }
        
        point curr = PQ.top(); 
        PQ.pop();
        // cout << "curr.x : " << curr.x << endl;
        // 큐에서 꺼낼 때 방문 체크
        if(visited[curr.x]) continue;
        visited[curr.x] = true;

        if(curr.x == K) {
            result = curr.time;
            return;
        }

        // 순간이동 (시간 0)
        int nx = curr.x * 2;
        if(nx <= MAX && !visited[nx]){
            PQ.push(point{nx, curr.time});
        }
        
        // 앞뒤 이동 (시간 +1)
        nx = curr.x + 1;
        if(nx <= MAX && !visited[nx]) {
            PQ.push(point{nx, curr.time + 1});
        }
        
        nx = curr.x - 1;
        if(nx >= 0 && !visited[nx]) {
            PQ.push(point{nx, curr.time + 1});
        }
        
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    dijkstra();

    cout << result << " \n";

    return 0;
}