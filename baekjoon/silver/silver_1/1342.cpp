#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
bool visited[10] = {false};
map<char, int> table;
string text;
int maxDepth;
int results = 0;

void initMap() {
    int i;
    char current;
    for(i = 0; i < text.size(); ++i) {
        current = text[i];
        if(table.count(current)) {
            table[current] += 1;
        }
        else {
            table[current] = 1;
        }
    }

}

void dfs(string current, int depth) {
    if(depth >= maxDepth) {
        results += 1;
        return;
    }

    char currentDepthUsed = '\0';
    for(int i = 0; i < text.size(); ++i) {
        if(visited[i]) continue;
        if(text[i] == currentDepthUsed) continue;
        if(!current.empty() && current.back() == text[i]) continue;

        current += text[i];
        visited[i] = true;
        dfs(current, depth + 1);
        current.pop_back();
        visited[i] = false;
        currentDepthUsed = text[i];
    }

}

int main() {
    cin >> text;
    maxDepth = text.size();
    string current = "";

    sort(text.begin(), text.end());
    initMap();
    if(maxDepth == table.size()) {
        results = 1;
        for(int i = 1; i <= table.size(); ++i) {
            results *= i;
        }
    }
    else dfs(current, 0);

    cout << results << endl;

}
