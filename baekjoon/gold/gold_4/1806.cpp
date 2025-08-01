#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0x7FFFFFFF
using namespace std;

int s,e, N,S;
vector<int> arr;
int minLength = MAX;
int sums = 0;

void init() {
    int i, temp;
    cin >> N >> S;
    for(i = 0; i < N; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }
    // cout << arr.size() << endl;
    s = 0;  e = 0;
    sums += arr[s];
}

void twoPointer() {

    while(s < N && e < N) {
        if(sums >= S) {
            minLength = min(minLength, e-s+1);
            sums -= arr[s];
            s++;
        } else {
            e++;
            if(e < N)
                sums += arr[e];
        }


    }
}

int main (){
    init();
    twoPointer();

    if(minLength == MAX)
        cout << 0 << endl;
    else    
        cout << minLength << endl;

    return 0;
}