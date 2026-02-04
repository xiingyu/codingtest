#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int>table;

void init() {
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) table.push_back(i);
}

void printArr(vector<int>& arr) {
    for(int i = 0; i < (int)arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void recur(int ind, int cnt, vector<int>& arr) {
    if(cnt >= M) {
        printArr(arr);
        return;
    }
    for(int i = ind; i < (int)table.size(); ++i) {
        arr.push_back(table[i]);
        recur(i, cnt + 1, arr);
        arr.pop_back();
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> arr;
    init();
    recur(0,0,arr);


    return 0;
}