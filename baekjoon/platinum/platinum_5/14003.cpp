#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;
vector<int> dp;
vector<int> befTable;

void init() {
    int temp;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin  >> temp;
        table.push_back(temp);
    }

    dp.resize(N, 1);
    befTable.resize(N, -1);
}

int logic() {
    int mxIndex = 0;
    int mxDPs = 0;
    for(int i = 1; i < N; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(table[i] > table[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                befTable[i] = j;
                if(mxDPs < dp[i]) {
                    mxDPs = dp[i];
                    mxIndex = i;
                }
            }
        }
    }
    return mxIndex;
}

void printTable() {
    cout << "befTable :" << endl;
    for(int i = 0; i < N; ++i) {
        cout << befTable[i] << " ";
    }
    cout << endl;
    cout << "dp :" << endl;
    for(int i = 0; i < N; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int mxIdx = logic();
    // printTable();
    // int mx = *max_element(dp.begin(), dp.end());
    // for(int i = N-1; i >= 0; --i) {
    //     if(dp[i] == mx) {
    //         mxIdx = i;
    //         break;
    //     }
    // }

    int idx = mxIdx;
    vector<int> ans;
    while(true) {
        ans.push_back(table[idx]);

        if(befTable[idx] == -1) break;
        idx = befTable[idx];
        
    }

    cout << ans.size() << '\n';
    for(int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    

    return 0;
}