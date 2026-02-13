#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int t;
struct point{
    int y,x;
};

int culCartesianDist(const point& a, const point&b) {
    return abs(a.y - b.y) + abs(a.x - b.x);
}

void printTable(vector<vector<int>> table, int n) {
    for(int i = 0; i < n+2; ++i) {
        for(int j = 0; j < n+2; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int n;
    point home, goal;
    cin >> t;

    while(t--) {
        cin >> n;
        cin >> home.x >> home.y;
        vector<point> store;
        vector<vector<int>> costTable;
        vector<vector<int>> nxt;

        store.push_back(home);
        for(int i = 0; i < n; ++i) {
            point temp;
            cin >> temp.x >> temp.y;
            store.push_back(temp);
        }
        cin >> goal.x >> goal.y;
        store.push_back(goal);

        costTable.resize(n+2, vector<int>(n+2, INF));
        nxt.resize(n+2, vector<int>(n+2, -1));
        for(int i = 0; i < n+2; ++i) {
            for(int j = 0; j < n+2; ++j) {
                if(i == j)  costTable[i][j] = 0;
                else if(culCartesianDist(store[i], store[j]) > 1000 ) continue;
                else {
                    costTable[i][j] = min(costTable[i][j],culCartesianDist(store[i], store[j]));
                    nxt[i][j] =j;
                }
            }
        }

        for(int k = 0; k < n+2; ++k) {
            for(int i = 0; i < n+2; ++i) {
                for(int j = 0; j < n+2; ++j) {
                    if(i == j) continue;
                    if(costTable[i][k] + costTable[k][j] < costTable[i][j]) {
                        costTable[i][j] = costTable[i][k] + costTable[k][j];
                        nxt[i][j] = nxt[i][k];
                        // cout << "is it works" <<endl;
                    }
                }
            }
        }
        // printTable(costTable, n);
        // printTable(nxt, n);

        int beer = 20;
        int region = 0;
        int next, culDist;
        while(region != n+1) {
            next = nxt[region][n+1];
            culDist = culCartesianDist(store[region], store[next]);

            // cout << "curr :" << store[region].x << " " << store[region].y << " next : " << store[next].x << " " << store[next].y;

            if(culDist % 50 == 0)   beer -= culDist/50;
            else                    beer -= ((culDist/50) + 1);

            // cout  << " culDist : " << culDist << " beer : " << beer <<endl;

            if(beer < 0 || next == -1)    {
                cout << "sad\n";
                break;
            }

            region = next;
            beer = 20;
        }
        if(region == n+1)   cout << "happy\n";



        
    }


    return 0;
}