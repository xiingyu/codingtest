#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> table;
vector<int> stack;
// vector<bool> visited;

void init() {
    int temp;
    cin >> N >> M;

    // visited.resize(N, false);

    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }
    sort(table.begin(), table.end());
}

void logic(int depth, int search) {
    if(depth >= M) {
        for(int i = 0; i < (int)stack.size(); ++i) {
            cout << stack[i] << " ";
        }
        cout << '\n';
        return;
    }

    int bef = 0;

    for(int i = search; i < (int)table.size(); ++i) {
        if(table[i] != bef) {
            bef = table[i];
            // visited[i] = true;
            stack.push_back(table[i]);
            logic(depth+1, i);
            // visited[i] = false;
            stack.pop_back();
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    logic(0, 0);

    return 0;
}