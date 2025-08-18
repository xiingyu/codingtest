#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0x7FFFFFFF
using namespace std;

int n,m;
vector<vector<int>> table;

void init() {
    int a,b,c;
    cin >> n >> m;

    table.resize(n+1,vector<int>(n+1, MAX));
    while(m--) {
        cin >> a >> b >> c;
        table[a][b] = min(table[a][b], c);
        // table[b][a] = min(table[b][a], c);
    }

    int j = 1;
    for(int i = 1; i <= n; ++i) {
        j = i;
        table[i][j] = 0;
    }
}

void fluid() {
    int i,j,k;
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            for(k = 1; k <= n; ++k) {
                if(table[j][i] == MAX || table[i][k] == MAX)
                    continue;
                table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
            }
        }
    }
}



void printTable() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    init();
    // printTable();
    // cout << endl;
    fluid();
    printTable();
    return 0;
}