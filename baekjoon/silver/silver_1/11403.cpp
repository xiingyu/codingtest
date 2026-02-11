#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> table;

void init() {
    int temp;
    cin >> N;
    table.resize(N, vector<int>(N, 0));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> temp;
            table[i][j] = temp;

            
        }
    }
}

void logic() {
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(table[i][k] == 1 && table[k][j] == 1) {
                    table[i][j] = 1;
                }
            }
        }
    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << table[i][j] << ' '; 
        }
        cout << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    logic();
    // logic();
    printTable();

    return 0;
}