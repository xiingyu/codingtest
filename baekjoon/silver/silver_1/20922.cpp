#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s,e, n,k;
int maxLength = 1;
vector<int> arr;
vector<int> numCnt;

void init() {
    int i, temp;
    cin >> n >> k;

    for(i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }

    int maxTemp = *max_element(arr.begin(),arr.end())+1;
    numCnt.resize(maxTemp, 0);

    s = 0;  e = 0;
    numCnt[arr[0]] += 1;

}

void twoPointer() {

    while(e < n && s < n) {
        if (e == s) {
            e++;
            continue;
        }
        if(numCnt[arr[e]] + 1 > k) {
            numCnt[arr[s++]] -= 1;
        } else {
            numCnt[arr[e]] += 1;
            e += 1;
        }
        
        // cout << s << " " << e << endl;
        maxLength = max(maxLength, e-s);
    }

}

void printMap() {
    for(int i = 0; i < n; ++i) {
        cout << numCnt[i] << " " << endl;
    }
}


int main() {
    init();
    // printMap();
    twoPointer();

    cout << maxLength << endl;

    return 0;
}