#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
bool visited[10];  // 최대 길이 10 가정
int resultsCnt = 0;

void dfs(string& current, int depth) {
    if (depth == str.size()) {
        resultsCnt++;
        return;
    }

    char prevChar = '\0';
    for (int i = 0; i < str.size(); ++i) {
        if (visited[i]) continue;
        if (str[i] == prevChar) continue;  // 중복 방지
        if (!current.empty() && current.back() == str[i]) continue;  // 연속 문자 방지

        visited[i] = true;
        current.push_back(str[i]);
        dfs(current, depth + 1);
        current.pop_back();
        visited[i] = false;
        prevChar = str[i];
    }
}

int main() {
    cin >> str;
    sort(str.begin(), str.end());  // 중복 제거의 핵심!

    string current = "";
    dfs(current, 0);

    cout << resultsCnt << endl;
}
