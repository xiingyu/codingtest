#include <iostream>
#include <vector>
#include <string>
using namespace std;

int M,N;
string s1;
string s2;
vector<char> str1;
vector<char> str2;
vector<vector<int>> commons;

void init() {
    cin >> s1;
    cin >> s2;

    str1.push_back(' ');
    for(char temp : s1) {
        str1.push_back(temp);
    }
    str2.push_back(' ');
    for(char temp : s2) {
        str2.push_back(temp);
    }
    M = (int)str1.size();
    N = (int)str2.size();

    commons.resize(N, vector<int>(M, 0));
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << commons[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    init();
    vector<char> ans;

    //LCS배치도 만들기
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j < M; ++j) {
            if(str1[j] == str2[i]) {
                commons[i][j] = commons[i-1][j-1] + 1;
            } else {
                commons[i][j] = max(commons[i-1][j],commons[i][j-1]);
            }
        }
    }

    //복원
    int y = N-1;
    int x = M-1;
    while(y > 0 && x > 0) {
        if(str1[x] == str2[y]) {
            ans.push_back(str1[x]);
            x--;    y--;
        } else if (commons[y-1][x] > commons[y][x-1]) {
            y--;
        } else {
            x--;
        }
    }
    // printTable();

    //출력
    cout << ans.size() << '\n';
    for(int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }

}