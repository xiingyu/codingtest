#include <iostream>
#include <vector>
using namespace std;

int n,m,s;
vector<vector<int>> table;

void init() {
    int a,b;
    cin >> n >> m;

    table.resize(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        table[a][b] = -1;    
        table[b][a] = 1;   
    }

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <=n; ++i) {
            for(int j = 1; j <=n; ++j) {
                if(i==j)    continue;
                if(table[i][k] == -1 && table[k][j] == -1) {
                    table[i][j] = -1;
                    table[j][i] = 1;
                }
            }
        }   
    }
}

void logic() {
    int a,b;
    cin >> s;

    while(s--) {
        cin >> a >> b;
        cout << table[a][b] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    init();
    logic();

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int n,m,s;
// vector<vector<int>> table;

// void init() {
//     int a,b;
//     cin >> n >> m;

//     table.resize(n+1, vector<int>(n+1, 0));

//     for(int i = 0; i < m; ++i) {
//         cin >> a >> b;
//         table[a][b] = -1;    
//     }

//     for(int k = 1; k <= n; ++k) {
//         for(int i = 1; i <=n; ++i) {
//             for(int j = 1; j <=n; ++j) {
//                 if(i==j)    continue;
//                 if(table[i][k] == -1 && table[k][j] == -1) {
//                     table[i][j] = -1;
//                 }
//             }
//         }   
//     }
// }

// void logic() {
//     int a,b;
//     cin >> s;

//     while(s--) {
//         cin >> a >> b;
//         if(table[a][b] == -1)   cout << -1;
//         else if(table[b][a] == -1)  cout << 1;
//         else cout << 0;
//         cout << '\n';
//         // cout << table[a][b] << '\n';
//     }
// }

// void printTable() {
//     for(int i = 1; i <= n; ++i) {
//         for(int j = 1; j <= n; ++j) {
//             cout << table[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);
    
//     init();
//     logic();

//     return 0;
// }