#include <iostream>
#include <vector>
#define MAX 1e9
using namespace std;

int V,E;
vector<vector<int>> costTable;

int mins(const int& a, const int&b) {
    return a < b ? a : b;
}

void init() {
    int a,b,c;
    cin >> V >> E;

    costTable.resize(V+1, vector<int>(V+1, MAX));
    for(int i = 0; i <= V; ++i) {
        costTable[i][i] = 0;
    }

    for(int i = 0; i < E; ++i) {
        cin >> a >> b >> c;
        
        costTable[a][b] = c;
    }
}

void floyd() {
    for(int i = 1; i <= V; ++i) {
        for(int j = 1; j <= V; ++j) {
            // if(i == j) continue;
            for(int k = 1; k<=V; ++k) {
                // if(i==k || j==k)    continue;
                costTable[i][j] = mins(costTable[i][j], costTable[i][k] + costTable[k][j]);
                // if(costTable[i][j] > costTable[i][k] + costTable[k][j]) {
                //     costTable[i][j] = costTable[i][k] + costTable[k][j];
                // }
                
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    init();
    floyd();

    int result = MAX;
    for(int i = 1; i <= V; ++i) {
        for(int j = 1; j <= V; ++j) {
            if(i != j) {
                result = mins(result, costTable[i][j] + costTable[j][i]);
            }
        }
    }

    cout << ((result >= MAX ) ? -1 : result);

    return 0;
}