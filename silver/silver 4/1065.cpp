#include <iostream>
#include <string>

using namespace std;

int is_deoungcha(int num) {
    if (num < 100) return 1; 
    string s_num = to_string(num);
    int arr[3] = {0};
    
    for(int i = (s_num.size()-1); i >= 1; --i) {
        arr[i] = s_num[i] - s_num[i-1];
    }

    if ((s_num.size()-1) == 4) {
        if ((arr[3] == arr[2]) && (arr[2] == arr[1])) {
            return 1;
        }
        else return 0;
    }

    else {
        if (arr[2] == arr[1]) {
            return 1;
        }
        else return 0;
    }

    return 0;
}

int main(void) {
    int n,i;
    cin >> n;

    int cnt = 0;
    for(i = 1; i <= n; ++i) {
        if ( is_deoungcha(i) == 1) cnt++;
    }

    cout << cnt << endl;

}