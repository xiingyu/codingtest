#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;
vector<int> ansArr;

void init() {
    cin >> N;
    table.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }
    ansArr.reserve(N);
}

void DPLogic() {
    int idx = 0;    int curr;
    ansArr.push_back(table[idx]);
    for(int i = 1; i < N; ++i) {
        curr = table[i];
        if(curr > ansArr[idx]) {
            ansArr.push_back(curr);
            idx++;
        } else {
            ansArr[lower_bound(ansArr.begin(), ansArr.begin()+idx, curr) - ansArr.begin()] = curr;
        }
    }
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    DPLogic();

    cout << ansArr.size();


    return 0;
}