#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
unsigned long long int result = 0;
vector<int> bags;
struct jew {
    int w,v;
};
vector<jew> targets;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w,v, b;
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> w >> v;
        targets.push_back(jew{w,v});
    }

    for(int i = 0; i < K; ++i) {
        cin >> b;
        bags.push_back(b);
    }

    sort(bags.begin(), bags.end());
    sort(targets.begin(), targets.end(), [](const jew& a, const jew&b) {
        return a.w < b.w;
    });
}

void logic() {
    priority_queue<int> pq;
    int idx = 0;
    for(int bag : bags) {
        while(idx < N && targets[idx].w <= bag) {
            pq.push(targets[idx].v);
            idx++;
        }
        if(!pq.empty()) {
            result += pq.top();  pq.pop();
        }
    }
}

int main() {
    init();
    logic();

    cout << result << "\n";

    return 0;
}