#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> degrees;
vector<int>parents;

void init() {
    int a,b;
    cin >> N;
    M = N;

    degrees.resize(N+1);
    parents.resize(N+1, 0);

    while(N--) {
        cin >> a >> b;

        degrees[a].push_back(b);
        degrees[b].push_back(a);
    }
}

bool isItParent(int target, int bef) {
    for(int parentCandidate : degrees[target]) {
        if(parentCandidate == bef)   continue;
        if(parentCandidate == 1)    return true;
        if(isItParent(parentCandidate, target)) return true;
    }

    return false;
}

int findParent(int target, int bef) {
    int answer = 0;
    for(int parentCandidate : degrees[target]) {
        // cout << parentCandidate << " " << target << " " << answer << endl;
        if(parentCandidate == bef)   continue;
        answer = parentCandidate;
        if(parentCandidate == 1)    return answer;
        if(isItParent(parentCandidate, target)) return answer;
    }

    return answer;
}


int main() {
    init();

    for(int i = 2; i <= M; ++i) {
        cout << findParent(i,0) << '\n';
    }

    return 0;
}