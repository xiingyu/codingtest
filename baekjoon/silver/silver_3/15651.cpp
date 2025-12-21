#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> arr;

void recurs(int depth) {
    if(depth == M + 1) {
        for(int i = 0; i < M; ++i) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; ++i) {
        arr[depth - 1] = i;
        recurs(depth + 1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    arr.resize(10, 0);

    recurs(1);

    return 0;
}

