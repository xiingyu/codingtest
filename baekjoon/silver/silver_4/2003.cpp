#include <iostream>
#include <vector>
using namespace std;

int s,e, n,m;
int result = 0;
vector<int> arr;

void init() {
    int i,temp;
    cin >> n >> m;
    for(i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }
    s = 0;
    e = 0;
}

// 1트, 24ms
// void binarySearch() {
//     int sums, i;
//     while(e < n && s < n) {
//         sums = 0;
//         for(i = s; i <= e; ++i) {
//             sums += arr[i];
//         }

//         if(sums > m) {
//             if(s==e) {e++; s++;}
//             else s++;
//         }
//         else if (sums < m) {
//             e++;
//         }
//         else {
//             result += 1;
//             e++;
//         }
//     }
// }

// 2트
void binarySearch() {
    int sums = 0;
    int i;

    while(e < n && s < n) {
        if(sums > m) {
            if(s==e) {
                e++; s++;
            }
            else {
                s++;
            }
        }
        else if (sums < m) {
            e++;
        }
        else {
            result += 1;
            e++;
        }
    }
}

int main() {
    init();
    binarySearch();
    cout << result << endl;

    return 0;
}