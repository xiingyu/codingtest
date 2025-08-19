#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0x7FFFFFFF
using namespace std;

int n,m;
vector<vector<int>>table;
vector<vector<int>>route;


void init() {
    int a,b,c;
    int i;
    cin >> n >> m;

    table.resize(n+1, vector<int>(n+1, MAX));
    route.resize(n+1, vector<int>(n+1, 0));

    while(m--) {
        cin >> a >> b >> c;
        table[a][b] = min(c, table[a][b]);
        route[a][b] = b;
    }

    for(i = 1; i <= n; ++i) {
        table[i][i] = 0;
    }

}

void fluid() {
    int i,j,k;

    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            for(k = 1; k <= n; ++k) {
                if((table[j][i] == MAX || table[i][k] == MAX)) {
                    continue;
                }
                else {
                    if(table[j][k] > table[j][i] + table[i][k]) {
                        table[j][k] = table[j][i] + table[i][k];
                        
                        route[j][k] = route[j][i];
                    }

                }

            }
        }
    }
}

void navigationPrint(int start, int goal) {
    if(table[start][goal] == 0) {
        cout << 0 << endl;
        return;
    }

    if(route[start][goal] == 0) {
        cout << 2 << " " << start << " " << goal << endl;
        return;
    }
    
    int temp = start;
    vector<int> naviRoute;
    while(temp != goal) {
        temp = route[temp][goal];
        naviRoute.push_back(temp);
    }
    cout << naviRoute.size() + 1 << " "<< start << " ";
    for(int i = 0; i < naviRoute.size(); ++i) {
        cout << naviRoute[i] << " ";
    }
    cout << endl;

    // cout << naviRoute.size() + 2 << " "<< start << " ";
    // for(int i = naviRoute.size()-1; i >= 0; --i) {
    //     cout << naviRoute[i] << " ";
    // }
    // cout << goal << endl;
}

void printMap() {
    int i,j;
    
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            if(table[i][j] == MAX) cout << 0 << " ";
            else cout << table[i][j] << " ";
        }
        cout << endl;
    }

}

void printRoute() {
    int i,j;
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            cout << route[i][j] << " ";
        }
        cout << endl;
    }

}


int main() {
    init();
    fluid();
    printMap();
    // printRoute();

    for(int i = 1; i <=n; ++i) {
        for(int j = 1; j <=n; ++j) {
            navigationPrint(i,j);
        }
    }
    

    return 0;
}