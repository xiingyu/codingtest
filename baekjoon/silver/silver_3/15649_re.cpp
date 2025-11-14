#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> arr;
vector<bool> visited;

void reculs(int depth) {
    if(depth == m+1) {
        for(int i = 1; i <= m; ++i) cout << arr[i] << ' '; 
        cout << '\n';
        return;
    }

    for(int i = 1; i < n+1; ++i) {
        if(visited[i]) continue;
        visited[i] = true;
        arr[depth] = i;

        reculs(depth + 1);

        visited[i] = false;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    arr.resize(m+1,0);
    visited.resize(m+1,false);

    reculs(1);

    return 0;
}
