#include <iostream>
#include <vector>


using namespace std;


int main(void) {
    int n,i,temp;
    cin >> n;
    vector<int> arr;
    vector<int> dp(n);

    for(i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
        cout << arr[i] << endl;
    }

}