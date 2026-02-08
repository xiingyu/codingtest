#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1e9
using namespace std;

int N;
int minimum = MAX;
vector<vector<int>> table;
vector<vector<int>> DP;

void init() {
    int R,G,B;
    cin >> N;

    table.resize(N, vector<int>(3, MAX));
    DP.resize(N, vector<int>(3, MAX));

    for(int i = 0; i < N; ++i) {
        cin >> R >> G >> B;
        table[i][0] = R;
        table[i][1] = G;
        table[i][2] = B;

    }

}

void DPs() {
    int temp = MAX;
    for(int i = 0; i < 3; ++i) {
        DP[0][i] = table[0][i];
    }
    for(int i = 1; i < N; ++i) {
        for(int curr = 0; curr < 3; ++curr) {
            temp = MAX;
            for(int target = 0; target < 3; ++target) {
                if(curr == target) continue;
                temp = min(DP[i-1][target] + table[i][curr], temp);
            }
            DP[i][curr] = temp;
        }
    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int curr = 0; curr < 3; ++curr) {
            cout << table[i][curr] << " " ;
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    DPs();
    
    cout << (*min_element(DP[N-1].begin(), DP[N-1].end()));

    return 0;
}