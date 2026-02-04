#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;
vector<int> dp;

void init() {
    int temp;
    cin >> N;
    dp.resize(N, 1);
    while(N--){
        cin >> temp;
        table.push_back(temp);
    }
}

void process() {
    
    for(int i = 1; i < (int)table.size(); ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(table[i] > table[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }

        }
    }

}

void printTable() {
    for(int i = 0 ; i < (int)table.size(); ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    process();

    // printTable();
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}