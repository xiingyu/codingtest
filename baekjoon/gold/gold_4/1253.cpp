#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;

void init() {
    int i, temp;
    cin >> N;
    for(i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }
    sort(table.begin(), table.end());
}

bool twoPointer(int s, int e, const int& target, const int& exceptIndex) {
    
    while(s < e) {
        int summ = table[s] + table[e];
        if(summ < target) {
            s++;
        }
        else if (summ > target) {
            e--;
        }
        else {
            if(s != exceptIndex && e != exceptIndex)    return true;
            else if (s == exceptIndex) s++;
            else if (e = exceptIndex) e--;
        }
    }

    return false;
}

int logic() {
    int count = 0;
    int target, funcResult;
    for(int i = 0; i < table.size(); ++i) {
        target = table[i];
        if(twoPointer(0,table.size()-1,target, i)) count++;
        else continue;
        
    }
    return count;
}

int main() {
    init();
    if(N == 1 || N == 2) {
        cout << 0 << endl;
    }
    else {
        int result = logic();

        cout << result << endl;
    }
    return 0;
}