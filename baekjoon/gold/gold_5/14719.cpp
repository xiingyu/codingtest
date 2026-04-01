#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H,W;
vector<int> map;

void init() {
    cin >> H >> W;
    map.resize(W, 0);
    for(int i = 0; i < W; ++i) {
        cin >> map[i];
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    init();

    int answer = 0;

    int left = 0; int right = 0;
    for(int curr = 1; curr < W - 1; ++curr) {
        left = *max_element(map.begin(), map.begin() + curr );
        right = *max_element(map.begin() + curr + 1 , map.end());

        answer += max(0, min(left,right) - map[curr]);
        // cout << curr << " " <<answer << endl;
    }

    cout << answer;

    return 0;
}