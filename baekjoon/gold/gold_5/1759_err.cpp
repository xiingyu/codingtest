#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L,C;
vector<char> moeums = {'a', 'e', 'i', 'o', 'u'};
vector<char> table;
vector<bool> visited;

void init() {
    int i;
    char temp;
    cin >> L >> C;

    visited.resize(C, false);

    for(i = 0; i < C; ++i) {
        cin >> temp;
        table.push_back(temp);
    }

    sort(table.begin(), table.end());
}

bool isItRight(const vector<char>& results) {
    int i;
    int moeumCnt = 0;
    int jaeumCnt = 0;
    bool isItMoeum = false;

    for(char target : results) {
        isItMoeum = false;
        for(char moeum : moeums) {
            if(target == moeum) {
                moeumCnt++;
                isItMoeum = true;
                break;
            }
            
        }
        if(!isItMoeum) jaeumCnt++;
        if(moeumCnt >= 1 && jaeumCnt >= 2)  return true;
    }
    return false;
}

void dfs(int depth, vector<char>& results, int lastSelect) {
    int i;
    
    if(depth >= L) {
        if(isItRight(results)) {
            for(char ch : results) {
                cout << ch;
            }
            cout << endl;
        }

        // for(i = 0; i < results.size(); ++i) {
        //     cout << "hi" << results[i] << endl;
        // }

        return;
    }

    for(i = lastSelect; i < table.size(); ++i) {
        if(visited[i])  continue;
        else {
            results.push_back(table[i]);
            visited[i] = true;

            dfs(depth + 1, results, i);

            results.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    vector<char> results;
    init();
    dfs(0, results, 0);

    return 0;
}