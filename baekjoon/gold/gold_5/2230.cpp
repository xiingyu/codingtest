#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 0x7FFFFFFF
using namespace std;

vector<int> arr;
vector<int> results;

int s, e, n, m;

void init() {
    int temp, i;
    cin >> n >> m;
    for(i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    s = 0;
    e = 0;
}

void twoPointer() {
    int min = MAX;
    int target;
    while(e < n && s < n) {
        // cout << "target is : " << target << endl;
        // cout << "s : " << s << " e : " << e << endl;
        target = arr[e] - arr[s];
        if(target < m) {
            e++;
        }
        else {
            // cout << target << "is pushed" << endl;
            results.push_back(target);
            s++;
        }
    }
}

int main() {
    init();
    twoPointer();

    cout << *min_element(results.begin(), results.end()) << endl;

    return 0;
}