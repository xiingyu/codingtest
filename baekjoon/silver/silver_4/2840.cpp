#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
using namespace std;
int n,k;
char lastPang;
list<char> luck;
unordered_set<char> isDouble;

void init() {
    int num;
    char target;
    for(int i = 0; i < n; ++i) {
        luck.push_back('?');
    }
    cin >> num >> target;
    list<char>::iterator it = luck.begin();
    *it = target;
    isDouble.insert(target);
}

bool logic() {
    int i, num;
    char target;
    list<char>::iterator it = luck.begin();
    for(i = 0; i < k-1; ++i) {
        cin >> num >> target;
        // cout << "inputted data : " << num << " & " << target << endl;
        for(int j = 0; j < num; ++j) {
            advance(it, 1);
            if(it == luck.end()) {
                it = luck.begin();
            }
        }
        if((*it != '?') &&(target != *it)) {
            // cout << *it << endl; 
            return false;
        }
        else {
            // if(isDouble.count(target)) return false;
            if(*it == '?' && isDouble.count(target)) return false;
            *it = target;
            if (i == k-2) lastPang = target;
            isDouble.insert(target);
        }
    }

    return true;

}

int main() {
    int startPoint;
    cin >> n >> k;
    init();
    bool flag = logic();
    if(flag == false) {
        cout << "!" << endl;
    }
    else {
        list<char>::iterator it = luck.begin();
        for(int i =0; i < k-1; ++i) {
            if(*it == lastPang) break;
            else {
                advance(it,1);
            }
        }
        for(int i =0; i < n; ++i) {
            cout << *it;
            if(it == luck.begin()) {
                it = luck.end();
                it--;
            }
            else advance(it,-1);
        }
    }

}