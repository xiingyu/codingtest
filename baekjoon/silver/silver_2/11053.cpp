#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;

void init() {
    int temp;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }
    // sort(table.begin(), table.end());
}

int main() {
    int count = 0;
    int bef = 0;
    init();
    for(int target : table) {
        if(bef < target) count++;
        bef = target;
    }
    cout << count << endl;
    return 0;
}