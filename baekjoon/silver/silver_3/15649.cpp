#include <iostream>
#include <vector>
using namespace std;

int n, m;

void printArr(const vector<int>& arr) {
    for(int i = 0; i < (int)arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

bool isInArr(int target, vector<int> arr) {
    for(int i = 0; i < (int)arr.size(); ++i) {
        if(arr[i] == target) return true;
    }

    return false;
}

void dfs(int start, vector<int> arr) {
    int depth = (int)arr.size();
    if(depth == m) {
        printArr(arr);
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(i == start) continue;
        if(isInArr(i, arr)) continue;
        arr.push_back(i);
        dfs(i, arr);
        arr.pop_back();
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    vector<int> arr;
    for(int i = 1; i <=n; ++i) {
        arr.push_back(i);
        dfs(i, arr);
        arr.pop_back();
    }



    return 0;
}