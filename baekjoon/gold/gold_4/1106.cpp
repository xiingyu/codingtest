#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, C;
struct advers{
    int cost; int customer;
};
vector<int> dp;
vector<advers> adver;

void init() {
    int co,cs;
    cin >> C >> N;
    dp.resize(100010, INF);
    for(int i = 0; i < N; ++i) {
        cin >> co >> cs;
        adver.push_back(advers{co,cs});
    }
    dp[0] = 0;
}

void DPLogic() {
    int currDP = 0;
    while(true) {
        for(int i = 0; i < N; ++i) {
            // if(dp[currDP] == INF)   break;

            advers curr = adver[i];
            dp[currDP + curr.customer] = min(dp[currDP] + curr.cost, dp[currDP + curr.customer]);

        }
        currDP++;
        if(currDP > C) return;
    }

}

void printTable()  {
    for(int i = 1040; i < C+55; ++i) {
        cout<< dp[i] << " ";
    }
    cout << endl;
    // cout << dp[1000];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    DPLogic();
    // printTable();

    cout << *min_element(dp.begin() + C, dp.end());

    return 0;
}