#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> table;

int findParent(const int& target) {
    if(table[target] == -1)
        return target;
    return table[target] = findParent(table[target]);
}

void uni(const int& a, const int& b) {
    int u = findParent(a);
    int v = findParent(b);
    if(u != v) {
        table[v] = u;
    }
}


void logic() {
    int comm, a,b;
    int u,v;
    
    cin >> N >> M;

    table.resize(N + 1, -1);

    while(M--) {
        cin >> comm >> a >> b;
        if(comm == 0) {
            uni(a,b);
        } else if(comm == 1) {
            cout << ((findParent(a) == findParent(b)) ? "YES\n" : "NO\n");
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    logic();

    return 0;
}