#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> DP;
struct product {
    int weight, value;
};
vector<product> products;


void init() {
    cin >> N >> K;

    products.resize(N+1);
    DP.resize(N+1, vector<int>(K+1, 0));

    for(int i = 1; i <= N; ++i) {
        int tempW, tempV;
        cin >> tempW >> tempV;
        products[i] = product({tempW,  tempV});
    }
}

void calculateDP() {
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= K; ++j) {
            if(j - products[i].weight >= 0) {
                DP[i][j] = max(DP[i-1][j], products[i].value + DP[i-1][j - products[i].weight]);
            }
            else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
}

void printMap() {
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= K; ++j) {
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    init();
    calculateDP();
    // printMap();

    cout << DP[N][K] << endl;

    return 0;
}