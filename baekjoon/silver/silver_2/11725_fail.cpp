#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> parents;
vector<vector<int>> degrees;

void init() {
    int a,b;
    cin >> N;

    degrees.resize(N+1);
    parents.resize(N+1, 0);

    for(int i = 0; i < N-1; ++i) {
        cin >> a >> b;

        degrees[a].push_back(b);
        degrees[b].push_back(a);
    }
}

bool findParents(int target, int bef) {
    for(int parentCandi : degrees[target]) {
        if(parentCandi == bef) continue;
        if(parentCandi == 1 || (parents[parentCandi] != 0)) {
            parents[target] = parentCandi;
            return true;
        } else {
            if(findParents(parentCandi, target)) {
                parents[target] = parentCandi;
                return true;
            }
        }
    }
    return false;
}

void culParents() {
    for(int i = 2; i <= N; ++i) {
        findParents(i, 0);
    }

}


int main() {
    init();
    culParents();

    for(int i = 2; i <= N; ++i) {
        cout << parents[i] << '\n';
    }

    return 0;
}