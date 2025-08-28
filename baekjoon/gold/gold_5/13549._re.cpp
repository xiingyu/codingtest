#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;

int N, K;
int result = 0;
int dx[] = {-1, 1};
struct point {
    int x, time;
};

void init() {
    cin >> N >> K;
}

void dijkstra() {
    int nx;
    queue<point> Q;
    Q.push(point{N, 0});

    while(!Q.empty()) {
        point curr = Q.front(); Q.pop();
        // cout << "curr.x : " << curr.x << endl;

        if(curr.x == K) {
            result = curr.time;
            return;
        }

        
        // if(curr.x < K && curr.x <= (int)(MAX/2) && curr.x != 0) {
        if(curr.x < K && curr.x != 0) {
            nx = curr.x * 2;
            while(nx <= MAX && nx <= K*2) {
                Q.push(point{nx, curr.time});
                nx*=2;
            }
            
        }

        if(curr.x > K) {
            Q.push(point{K, curr.time + curr.x - K});
        }
        else {
            for(int i = 0; i < 2; ++i) {
                nx = curr.x + dx[i];

                if(nx < 0 || nx > MAX) continue;

                Q.push(point{nx, curr.time + 1});
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