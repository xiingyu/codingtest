#include <iostream>
#include <vector>
using namespace std;

int n;
vector<unsigned long long int> dp = {0,1,1,1,2,2,3,4,5,7,9};

void appendTo(int inData) {
    for(int i = dp.size(); i <= inData; ++i) {
        dp.push_back(dp[i-1] + dp[i-5]);
    }

}

int main() {
    int temp;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        if(temp >= dp.size()) {
            appendTo(temp);
        }
        cout << dp[temp] << endl;
    }
}