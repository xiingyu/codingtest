#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, M;
set<string> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int cnt = 0;
    string temp;
    cin >> N >> M;

    while(N--) {
        cin >> temp;
        S.insert(temp);
    }

    while(M--) {
        cin >> temp;
        if(S.find(temp) != S.end()) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}