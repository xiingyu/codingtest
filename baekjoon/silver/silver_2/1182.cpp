#include <iostream>
#include <vector>
using namespace std;
int n,s;
vector<int> arr;

void input(void) {
    int i,temp;
    for(i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }    
}

int force() {
    int max_bit = 1 << n;
    int bit, i;
    int results = 0;
    for(bit = 0; bit < max_bit; ++bit) {
        int sums = 0;
        for(i = 0; i < n; ++i) {
            if(bit & (1 << i))
                sums += arr[i];
                // cout << sums << endl;
        }
        if (sums == s) {
            results += 1;
        }
    }
    // cout << s << " " << results << endl;
    if (s == 0) return results-1;
    return results;
}

int main(void) {
    cin >> n >> s;
    input();
    cout << force() << endl; 
}