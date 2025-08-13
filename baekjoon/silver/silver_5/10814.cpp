#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,string>> table;

int main() {
    int i, temp;
    string tempString;
    cin >> N;
    while(N--) {
        cin >> temp >> tempString;
        table.push_back(pair{temp, tempString});
    }

    stable_sort(table.begin(), table.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    for(i = 0; i < table.size(); ++i) {
        cout << table[i].first << " " << table[i].second << '\n';
    }
    cout << endl;

    return 0;
}