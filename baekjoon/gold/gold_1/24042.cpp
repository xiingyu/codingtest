#include <iostream>
#include <queue>
#include <vector>
#define MAX (((long long int)1<<63) - 1)
using namespace std;

struct point {
    int place;
    long long int time;
};

struct node {
    int end, cost;
};

auto cmp = [](const point& a, const point& b) {
    return a.time > b.time;
};

int N,M;
long long int result = 0;
vector<long long int> minArrivalTime;
vector<vector<node>> table;
priority_queue<point, vector<point>, decltype(cmp)> PQ(cmp);

void init() {
    int u,v;

    cin >> N >> M;
    table.resize(N+1);
    minArrivalTime.resize(N+1, MAX);
    for(int i = 1; i <= M; ++i) {
        cin >> u >> v;
        table[u].push_back(node{v,i});
        table[v].push_back(node{u,i});
    }
}

void dijkstra() {
    int start = 1;  int goal = N;

    if(start == goal) return;

    PQ.push(point{start, 0});

    while(!PQ.empty()) {
        point curr = PQ.top();  PQ.pop();

        // if(minArrivalTime[curr.place] < curr.time) {
        //     continue;
        // } else {
        //     minArrivalTime[curr.place] = curr.time;
        // }

        if(curr.place == goal) {
            result = curr.time;
            return;
        }

        long long int depth = (int)(curr.time / M);
        long long int stage = curr.time % M;
        
        for(node next : table[curr.place]) {
            long long int ncost;
            if(next.cost <= stage) {
                ncost = (depth + 1) * M + next.cost;
            } else {
                ncost = (depth) * M + next.cost;
            }

            if(minArrivalTime[next.end] > ncost) {
                minArrivalTime[next.end] = ncost;
                PQ.push(point{next.end, ncost});
            }
            
            
            // cout << "curr : "<< curr.place << " goto : " << next.end << " depth : " << depth << " stage : " << stage << " curr.time : " << curr.time << endl;
        }
        

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    dijkstra();

    cout << result <<endl;

    return 0;
}