#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
string word;
map<char,int> table;

int logic() {
    char bef = 0;
    word.clear();   table.clear();
    cin >> word;
    for(int i = 0; i < word.size(); ++i) {
        char ch = word[i];
        if(bef != ch && table.count(ch)) {
            return 0;
        }
        else {
            table[ch] = 1;
            bef = ch;
        }
    }
    return 1;
}

int main() {
    int results = 0;
    cin >> n;
    while(n--) {
        results += logic();
    }
    cout << results << endl;
}