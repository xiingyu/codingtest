#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int N;
string enter = "enter";
string leave = "leave";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    set<string> S;
    cin >> N;

    while(N--) {
        string name, state;

        cin >> name >> state;
        if(state == enter) S.insert(name);
        else S.erase(name);
    }
    

    
    for(auto it = S.rbegin(); it != S.rend(); ++it) {
        cout << *it<<'\n';
    }
    

    return 0;
}