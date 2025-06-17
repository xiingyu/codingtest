#include <iostream>
#include <vector>

using namespace std;

int findmax(vector<int>& dp_result) {
    int i,temp,max_val;
    max_val = dp_result[0];
    for (i = 0; i < dp_result.size(); ++i) {
        if (dp_result[i] > max_val) {
            max_val = dp_result[i];
        }
    }
    return max_val;
}

int compare(int a, int b) {
    return a>b ? a : b;
}

void dp_making(vector<int>& dp, vector<int>& arr) {
    dp[0] = arr[0];
    dp[1] = compare(dp[0] + arr[1], arr[1]);

    for (int i = 2; i < arr.size(); ++i) {
        dp[i] = compare(dp[i-1] + arr[i], arr[i]);
    }
}


int main(void) {
    int n,i,temp;
    cin >> n;
    vector<int> arr;
    vector<int> dp(n);

    for(i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
        dp[i] = temp;
    }
    dp_making(dp,arr);
    cout << findmax(dp) << endl;


}