#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;
vector<int> ans;

void init() {
    cin >> N;

    int temp;
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();

    int idx = 1; int temp;
    ans.push_back(table[0]);

    for(int i = 0; i < N; ++i) {
        temp = table[i];
        if(temp > ans[idx-1]) {
            ans.push_back(temp);
            idx++;
        } else {
            ans[lower_bound(ans.begin(), ans.begin() + idx, temp) - ans.begin()] = temp;
        }
    }

    cout << idx;


    return 0;
}