#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n,dis,i, s,m,e;
    cin >> n >> dis;
    vector<vector<int>> cross;

    for(i = 0; i < n; ++i) {
        cin >> cross[i][0] >> cross[i][1] >> cross[i][2];
    }
    printf("%d %d %d\n",cross[0][0],cross[0][1],cross[0][2]);
}