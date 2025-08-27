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
    visited[N] = true;

    while(!PQ.empty()) {
        point curr = PQ.top(); PQ.pop();
        // cout << "curr.x : " << curr.x << endl;

        if(curr.x == K) {
            result = curr.time;
            return;
        }

        
        // if(curr.x < K && curr.x <= (int)(MAX/2) && curr.x != 0) {
        if(curr.x < K && curr.x != 0) {
            nx = curr.x * 2;
            while(nx <= MAX && nx <= K*2) {
                visited[nx] = true;
                PQ.push(point{nx, curr.time});
                nx*=2;
            }
            
        }

        if(curr.x > K) {
            PQ.push(point{K, curr.time + curr.x - K});
        }
        else {
            for(int i = 0; i < 2; ++i) {
                nx = curr.x + dx[i];

                if(nx < 0 || nx > MAX) continue;

                visited[nx] = true;
                PQ.push(point{nx, curr.time + 1});
            }
        }

        // for(int i = 0; i < 2; ++i) {
        //     nx = curr.x + dx[i];

        //     if(nx < 0 || nx > MAX) continue;

        //     PQ.push(point{nx, curr.time + 1});
        // }
        
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