#include <iostream>
#include <vector>
using namespace std;

int N,K;
vector<int> coins;
vector<int> dp;

void init() {
    cin >> N >> K;
    coins.resize(N);
    dp.resize(K+1, 0);

    for(int i = 0 ; i < N; ++i) {
        cin >> coins[i];
    }
    dp[0] = 1;
}

void DPLogic() {
    int curr;
    for(int i = 0; i < N; ++i) {
        curr = coins[i];
        for(int target = curr; target <= K; ++target) {
            dp[target] = dp[target] + dp[target - curr];
        }
    }
}


int main() {
    ios::sync_with_stdio(0);    cin.tie(0); cout.tie(0);
    init();
    DPLogic();

    cout << dp[K];



    return 0;
}