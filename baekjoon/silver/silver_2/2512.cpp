#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0x7FFFFFFF
using namespace std;

int N, M, maxH;
vector<int> table;

void init() {
    int i, temp;

    cin >> N;
    for(i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }
    cin >> M;
    maxH = *max_element(table.begin(), table.end());
}

int makeBudget(int cut) {
    long int count = 0;
    for(int target : table) {
        if(target >cut) count += cut;
        else count += target;
        if(count > MAX) return MAX;
    }
    return count;
}

int binarySearch(int s, int e) {
    int mid, result = 0;
    int budget;
    while(s < e) {
        mid = (s + e) / 2;

        budget = makeBudget(mid);
        // cout << s << " " << e  << " " << mid << " " << budget << endl;
        if(budget > M) {
            e = mid;
        }
        else if(budget < M) {
            result = mid;
            s = mid + 1;
        } else {
            result = mid;
            break;
        }
        
    }
    return result;
}

int main() {
    init();
    // cout << maxH << endl;
    int result = binarySearch(0,maxH+1);

    cout << result << endl;

    return 0;
}
