#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
queue<int> que;
vector<int> inDegree;
vector<vector<int>> nexts;

vector<int> results;

void init() {
    int s,e, i;
    cin >> N >> M;

    inDegree.resize(N+1, 0);
    nexts.resize(N+1);
    for(i = 0; i < M; ++i) {
        cin >> s >> e;
        nexts[s].push_back(e);
        inDegree[e] += 1;
    }
    for(i = 1; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) {
            que.push(i);
            results.push_back(i);
        }
    }
}

void logic() {

    while(!que.empty()) {
        int curr = que.front(); que.pop();

        for(int next : nexts[curr]) {
            inDegree[next] -= 1;
            if(inDegree[next] == 0) {
                que.push(next);
                results.push_back(next);

            }
        }
    }

}

int main() {
    init();
    logic();
    for(int student : results) {
        cout << student << " ";
    }

}