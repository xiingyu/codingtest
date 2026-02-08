#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e9
using namespace std;

int N;
vector<vector<int>> table;
vector<vector<int>> DP;

void init() {
    int temp;
    int repeat = 0;
    cin >> N;

    table.resize(N, vector<int>(N, -1));
    DP.resize(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; ++i) {
        repeat++;
        for(int j = 0; j < repeat; ++j) {
            cin >> temp;
            table[i][j] = temp;
        }
    }
}

void logic() {
    int temp;
    DP[0][0] = table[0][0];

    for(int i = 0; i < N-1; ++i) {
        for(int curr = 0; curr < N; ++curr) {
            if(table[i][curr] == -1)    break;
            DP[i+1][curr]   = max(DP[i+1][curr], DP[i][curr] + table[i+1][curr]);
            DP[i+1][curr+1] = max(DP[i+1][curr+1], DP[i][curr] + table[i+1][curr+1]);
        }
    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(table[i][j] == -1)   break;
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void printDPTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(table[i][j] == -1)   break;
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    logic();

    cout << (*max_element(DP[N-1].begin(), DP[N-1].end()));

    return 0;
}