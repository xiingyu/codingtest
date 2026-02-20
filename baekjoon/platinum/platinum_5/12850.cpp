#include <iostream>
#include <vector>
#define MOD 1000000007LL
typedef long long ll;
using namespace std;

int N = 8;

vector<vector<ll>> table = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

vector<vector<ll>> multiple(const vector<vector<ll>>& map1, const vector<vector<ll>>& map2) {
    vector<vector<ll>> retval(N, vector<ll>(N));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            ll temp = 0;
            for(int k = 0; k < N; ++k) {
                temp += map1[i][k] * map2[k][j];
                temp %= MOD;
            }
            retval[i][j] = temp % MOD;
        }
    }
    return retval;
}

int main() {
    ll D;
    cin >> D;

    vector<vector<ll>> resultMatrix(N, vector<ll>(N));
    vector<vector<ll>> ans(N, vector<ll>(N,0));
    for(int i = 0; i < N; ++i) ans[i][i] = 1;
    resultMatrix = table;

    while(D) {
        if(D&1) {
            ans = multiple(ans, resultMatrix);
            D--;
        }
        resultMatrix = multiple(resultMatrix, resultMatrix);
        D /= 2;
    }

    cout << ans[0][0];


    return 0;
}