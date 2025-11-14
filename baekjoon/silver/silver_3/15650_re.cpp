#include <iostream>
#include <vector>
using namespace std;

int N,M;

void reculs(int start, vector<int> arr) {
    int size = (int)arr.size();
    if(size >= M) {
        for(int i = 0; i < M; ++i) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }


    for(int i = start + 1; i <= N; ++i) {
        arr.push_back(i);
        reculs(i, arr);
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 1; i <= N - M + 1; ++i) {
        vector<int> arr = {i};
        reculs(i, arr);
    }

    return 0;
}