#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N;
int ans = INF;
vector<vector<int>> table;
vector<vector<int>> dp;

void init() {
    cin >> N;

    table.assign(N,vector<int>(3));
    dp.assign(N, vector<int>(3, INF));
    for(int i = 0; i < N; ++i) {
        cin >> table[i][0] >> table[i][1] >> table[i][2];
    }

    for(int i = 0; i < 3; ++i) {
        dp[0][i] = table[0][i];
    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}



void DPLogic() {
    for(int rgb = 0; rgb < 3; ++rgb) {
        for(int i = 0; i < 3; ++i) {
            if(rgb == i)   dp[1][i] = INF;
            else {
                dp[1][i] = table[1][i] + table[0][rgb];
            }
        }

        for(int i = 2; i < N; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(j == 0) {
                    dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + table[i][j];
                } else if (j == 1) {
                    dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + table[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][1], dp[i-1][0]) + table[i][j];
                }
            }
        }

        for(int i = 0; i < 3; ++i) {
            if(rgb == i)    continue;
            else {
                ans = min(ans, dp[N-1][i]);
                // printTable();
            }
        }

    }


    

    // for(int j = 0; j < 3; ++j) {
    //     for(int k = 0; k < 3; ++k) {
    //         if(j == k) continue;
    //         dp[N-2][j] = min(dp[N-1][k])
    //     }
    // }


}




int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    DPLogic();
    // printTable();


    cout << ans;


    return 0;
}