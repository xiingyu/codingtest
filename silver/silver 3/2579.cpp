#include <iostream>
#include <vector>
using namespace std;

int compare(int a, int b) {
    return (a > b) ? a : b;
}

void dp_making(vector<int>& dp, vector<int>& stair) {
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = stair[0] + stair[2];


    for (int i = 3; i < stair.size(); ++i) {
        dp[i] = compare(dp[i-1], dp[i-2]) + stair[i];
        cout << dp[i] << endl;
    }
}

int main(void) {
    int n,i,temp;
    cin >> n;

    vector<int> stair;
    vector<int> dp(n);
    for(i = 0; i < n; ++i) {
        cin >> temp;
        stair.push_back(temp);
    }

    //processing start
    dp_making(dp,stair);
    cout << dp[n-1] << endl;
}