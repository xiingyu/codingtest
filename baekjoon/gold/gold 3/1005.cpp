#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T,N,K;
vector<int> inDegree, timeTakes, costs, results;
vector<vector<int>> nexts, prevs;
queue<int> que;

void init() {
    int i,temp, s,e;
    cin >> N >> K;
    

    inDegree.clear();   inDegree.resize(N+1, 0);
    timeTakes.clear();  timeTakes.resize(N+1, 0);
    costs.clear();  costs.resize(N+1, 0);
    nexts.clear();  nexts.resize(N+1);
    prevs.clear();  prevs.resize(N+1);

    for(i = 1; i <= N; ++i) {
        cin >> temp;
        costs[i] = temp;
    }
    
    for(i = 0; i < K; ++i) {
        cin >> s >> e;
        nexts[s].push_back(e);
        inDegree[e] += 1;
        prevs[e].push_back(s);
        // cout << s << " " << e << endl;
    }

    for(i = 1; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0) {
            que.push(i);
            timeTakes[i] = costs[i];
        }
    }
}

int logic() {
    int i, curr;

    while(!que.empty()) {
        curr = que.front(); que.pop();

        for(i = 0; i < nexts[curr].size(); ++i) {
            inDegree[nexts[curr][i]] -= 1;
            timeTakes[nexts[curr][i]] = max(timeTakes[nexts[curr][i]] - costs[nexts[curr][i]], timeTakes[curr]) + costs[nexts[curr][i]];
            if(inDegree[nexts[curr][i]] == 0) {
                que.push(nexts[curr][i]);
                // timeTakes[nexts[curr][i]] = max(timeTakes[nexts[curr][i]] - costs[nexts[curr][i]], timeTakes[curr]) + costs[nexts[curr][i]];
            }
        }
    }
    return curr;
}

int main() {
    int resultTemp, finalBuild;
    cin >> T;
    while(T--) {
        init();
        results.push_back(logic());
        cin >> finalBuild;
        cout << timeTakes[finalBuild] << endl;
    }


}