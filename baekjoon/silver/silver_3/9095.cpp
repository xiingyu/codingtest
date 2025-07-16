#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> dp(12,0);

void logic() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 11; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
}

void inNout() {
    int i, target;
    cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> target;
        cout << dp[target] << endl;
    }
}

int main() {
    logic();
    inNout();
}