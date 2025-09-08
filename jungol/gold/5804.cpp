#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,C;
vector<int> table;
vector<int> betweens;

void init() {
    int temp;
    cin >> N >> C;

    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }

    sort(table.begin(), table.end());

    for(int i = 0; i < N-1; ++i) {
        betweens.push_back(table[i+1] - table[i] );
    }
}

bool isItOkay(const int& target) {
    int tempSums = 0;
    int result = 0;
    for(int i = 0; i < N-1; ++i) {
        tempSums += betweens[i];
        
        if(tempSums >= target) {
            result++;
            tempSums = 0;
        }
        // cout << tempSums << " " << result << endl;
        if(result >= C-1) return true;
    }
    return false;
}

int binaryLogic() {
    int mid;
    int left = 1;
    int right = table.back();
    int befMid = -1;


    while(left < right) {
        mid = (left + right) / 2;

        // cout << "mid : " << mid << endl;

        if(isItOkay(mid)) {
            if(befMid == mid) break;
            else left = mid;
        } else {
            right = mid;
        }
        befMid = mid;
    }
    return mid;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    if(C == 2) {
        cout << table.back() - table.front();
    } else {
        cout << binaryLogic();
        // isItOkay(50);
    }


    return 0;
}