#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> inDegree, results;
vector<vector<int>> nexts;
queue<int> que;

void init() {
    int i,j, iter, s,e, sprev, eprev;
    cin >> N >> M;

    nexts.resize(N+1);
    inDegree.resize(N+1,0);

    for(i = 0; i < M; ++i) {
        cin >> iter;
        cin >> s >> e;
        nexts[s].push_back(e);
        inDegree[e] += 1;
        // cout << "at " << s << " pushed " << e << endl;
        s = e;
        for(j = 0; j < iter-2; ++j) {
            cin >> e;
            nexts[s].push_back(e);
            // cout << "at " << s << " pushed " << e << endl;
            inDegree[e] += 1;
            s = e;
        }
    }
    
    for(i = 1; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0) {
            que.push(i);
            // cout << i << " is pushed" << endl;
            results.push_back(i);
        }
    }

}

void logic() {
    int i;
    while(!que.empty()) {
        int curr = que.front(); que.pop();

        for(i = 0; i < nexts[curr].size(); ++i) {
            inDegree[nexts[curr][i]] -= 1;
            // cout << nexts[curr][i] << " is searched" << endl;
            if(inDegree[nexts[curr][i]] == 0) {
                que.push(nexts[curr][i]);
                // cout << nexts[curr][i] << " is pushed" << endl;
                results.push_back(nexts[curr][i]);

            }
            
        }
    }

}

int main() {
    init();
    logic();
    if(results.size() != N) cout << 0 << endl;
    else {
        for(int i : results) {
            cout << i << endl;
        }
    }
}