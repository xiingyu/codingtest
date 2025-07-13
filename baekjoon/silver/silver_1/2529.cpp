#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<char> uneq;
vector<vector<int>> results;

void findAry(int depth, int bef, vector<int> current, vector<bool>& visited) {
    if(depth >= n) {
        results.push_back(current);
        return;
    }

    if(uneq[depth] == '<') {
        for(int i = bef + 1; i <= 9; ++i) {
            if(visited[i] == true) continue;
            else {
                current.push_back(i);
                visited[i] = true;
                findAry(depth + 1, i, current, visited);
                visited[i] = false;
                current.pop_back();
            }
        }
    }
    else {
        for(int i = bef - 1; i >= 0; --i) {
            if(visited[i] == true) continue;
            else {
                current.push_back(i);
                visited[i] = true;
                findAry(depth + 1, i, current, visited);
                visited[i] = false;
                current.pop_back();
            }
        }

    }

}

void printMap() {
    cout << results[0].size() << endl;
    for(int i = 0; i < results.size(); ++i) {
        for(int j = 0; j < results[0].size(); ++j) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}

void printAns() {
    vector<int>max_ele= *max_element(results.begin(), results.end());
        for(int i = 0; i < n+1; ++i) {
        cout << max_ele[i];
    }
    cout << endl;
    for(int i = 0; i < n+1; ++i) {
        cout << results[0][i];
    }
}


int main(void) {
    char temp;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        uneq.push_back(temp);
    }
    vector<bool> visited(n+2,false);
    vector<int> curr;

    for(int i = 0; i <= 9; ++i) {
        visited[i] = true;
        curr.push_back(i);
        findAry(0, i, curr, visited);
        visited[i] = false;
        curr.pop_back();
    }
    // printMap();
    printAns();


}