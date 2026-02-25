#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int T, n,m;

vector<int> ATable;
vector<int> BTable;
vector<vector<int>> dpA;
vector<vector<int>> dpB;

vector<int> stripDPA;
vector<int> stripDPB;

void init() {
    int temp;

    cin >> T >> n;
    dpA.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        ATable.push_back(temp);
        dpA[i][i] = temp;
    }

    cin >> m;
    dpB.resize(m, vector<int>(m, 0));
    for(int i = 0; i < m; ++i) {
        cin >> temp;
        BTable.push_back(temp);
        dpB[i][i] = temp;
    }

    
    
}

void dpLogic() {
    dpA[0][0] = ATable[0];  stripDPA.push_back(ATable[0]);
    for(int from = 0; from < n; ++from) {
        for(int to = from; to < n; ++to) {
            if(to == 0) continue;
            dpA[from][to] = dpA[from][to - 1] + ATable[to];
            stripDPA.push_back(dpA[from][to]);
        }
    }

    dpB[0][0] = BTable[0];  stripDPB.push_back(BTable[0]);
    for(int from = 0; from < m; ++from) {
        for(int to = from; to < m; ++to) {
            if(to == 0) continue;
            dpB[from][to] = dpB[from][to - 1] + BTable[to];
            stripDPB.push_back(dpB[from][to]);
        }
    }

    // dpA.clear();
    // dpB.clear();
    sort(stripDPA.begin(), stripDPA.end());
    sort(stripDPB.begin(), stripDPB.end());
}

void printTable() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << dpA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << dpB[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

ll findSameThings(const int& idx, const int& target) {
    ll ans = 0;
    // if(idx >= stripDPB.size() - 1)  return ans;
    // while(stripDPB[idx] == target) {
    //     ans++;  idx++;
    //     if(idx >= stripDPB.size() - 1)  return ans;
    // }

    // cout << target <<" " <<  idx << " " << stripDPB.size() << endl;
    if(idx >= stripDPB.size())  return ans;
    int next = lower_bound(stripDPB.begin(), stripDPB.end(), target + 1) - stripDPB.begin();
    // if(next >= stripDPB.size())  return ans;
    


    return next - idx;
}

ll findAns() {
    ll ans = 0;

    int target = 0;
    for(int i = 0; i < (int)stripDPA.size(); ++i) {
        target = T - stripDPA[i];
        ans += findSameThings(lower_bound(stripDPB.begin(), stripDPB.end(), target) - stripDPB.begin(), target);
        // cout<< "target : " << target << " binary : ";
        // cout << lower_bound(stripDPB.begin(), stripDPB.end(), target) - stripDPB.begin() << endl;

    }


    // int currA;  int currB;  int curr;
    // for(int Afrom = 0; Afrom < n; ++Afrom) {
    //     for(int Ato = Afrom; Ato < n; ++Ato) {
    //         currA = dpA[Afrom][Ato];
    //         for(int Bfrom = 0; Bfrom < m; ++Bfrom) {
    //             for(int Bto = Bfrom; Bto < m; ++Bto) {
    //                 currB = dpB[Bfrom][Bto];
    //                 curr = currA + currB;

    //                 if(curr == T) {
    //                     ans++;
    //                     // cout << "currA : " << currA << " currB : " << currB << endl;
    //                 }
    //             }
    //         }
    //     }
    // }

    return ans;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    dpLogic();
    // printTable();

    cout << findAns();


    return 0;
}