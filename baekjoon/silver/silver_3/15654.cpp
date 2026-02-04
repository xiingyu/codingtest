#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N,M;
vector<int>table;

void init() {
    int temp;
    cin >> N >> M;
    while(N--) {
        cin >> temp;
        table.push_back(temp);
    }
    sort(table.begin(), table.end());
}

void printArr(vector<int>& arr) {
    for(int i = 0; i < (int)arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void recur(int ind, int cnt, vector<int>& arr, set<int> indxs) {
    if(cnt >= M) {
        printArr(arr);
        return;
    }
    
    for(int i = 0; i < (int)table.size(); ++i) {
        if(indxs.find(i) != indxs.end())    continue;
        arr.push_back(table[i]);
        indxs.insert(i);
        recur(i, cnt+1, arr, indxs);
        arr.pop_back();
        indxs.erase(i);
    }

    // for(int i = ind + 1; i < (int)table.size(); ++i) {
    //     if(i >= (int)table.size())  continue;
    //     arr.push_back(table[i]);
    //     recur(i, cnt + 1, arr);
    //     arr.pop_back();
    // }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> arr;
    set<int> indxs;
    init();
    for(int i = 0; i < (int)table.size(); ++i) {
        arr.push_back(table[i]);
        indxs.insert(i);
        recur(i, 1, arr, indxs);
        arr.pop_back();
        indxs.erase(i);
    }


    return 0;
}