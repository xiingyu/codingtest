#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, K;
vector<int> coins;
vector<int> dp;

void init() {
    int temp;
    cin >> N >> K;
    dp.resize(K+1, INF);

    for(int i = 0; i < N; ++i) {
        cin >> temp;
        if(temp > K) continue;
        coins.push_back(temp);
        dp[temp] = 1;
    }
    sort(coins.begin(), coins.end());
    // if(coins.empty()) cout << "empty";
    

}

void DPLogic() {
    int curr;
    for(int i = 1; i <= K; ++i) {
        for(int coin : coins) {
            curr = i - coin;
            if(curr <= 0)   break;
            dp[i] = min(dp[i], dp[curr] + 1);
        }
    }
}

void printTable() {
    for(int i : dp) {
        if(i == INF) cout << "F ";
        else cout << i << " ";
    }
}

int main() {
    init();
    DPLogic();
    // printTable();
    if(dp[K] == INF) cout << -1;
    else     cout << dp[K];
}