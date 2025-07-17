#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
unordered_map<string, int> wear;
vector<string> typeWear;

void input() {
    int m;
    cin >> m;
    string c,type;
    typeWear.clear();
    wear.clear();
    for(int i = 0; i <m; ++i) {
        cin >> c >> type;
        if(wear.find(type) != wear.end()) {
            wear[type] += 1;
        }
        else {
            wear[type] = 2;
            typeWear.push_back(type);
        }
    }
}

int logic() {
    // cout << "typeWear.size() : " << typeWear.size() << endl;
    int i;
    int result = 1;
    for(i = 0; i < typeWear.size(); ++i) {
        result *= wear[typeWear[i]];

    }
    return result;
}

int main() {
    int result;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        input();
        result = logic();
        cout << result - 1 << endl;;

    }
}