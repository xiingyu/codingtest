#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;

struct consult {
    int s,due,e,cost;
};
vector<consult> cont;

void input() {
    int tmp0, tmp1;
    for(int i = 1; i <= n; ++i) {
        cin >> tmp0 >> tmp1;
        cont.push_back(consult{i, tmp0, i+tmp0, tmp1});
    }
}

int ismax(int a, int b) {
    return a>b ? a : b;
}


void logic() {
    int today,i,j;
    int max_temp = 0;
    for(today = 1; today < n+2; ++today) {
        vector<consult> max_arr;
        for(i = 0; i < cont.size(); ++i) {
            if(cont[i].e == today) {
                max_temp = ismax(dp[cont[i].s] + cont[i].cost, max_temp);
        // cout << cont[i].s << " " << cont[i].due << " " << cont[i].e << " " << cont[i].cost << " " << endl;
            }
            dp[today] = ismax(max_temp, dp[i-1]);
        }
    }

}

void printmap() {
    int i;
    for(i = 0; i < cont.size(); ++i) {
        cout << cont[i].s << " " << cont[i].due << " " << cont[i].e << " " << cont[i].cost << " " << endl;
    }
}


int main(void) {
    cin >> n;
    dp.resize(n+2, 0);
    dp[1] = 0;
    input();
    // printmap();
    logic();
    cout << dp[n+1];
}