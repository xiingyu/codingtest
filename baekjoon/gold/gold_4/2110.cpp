#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,C = 0;
vector<int> originTable;
vector<int> distanceTable;


void init() {
    int temp;
    cin >> N >> C;

    for(int i = 0; i < N; ++i) {
        cin >> temp;
        originTable.push_back(temp);
    }

    sort(originTable.begin(), originTable.end());
    for(int i = 1; i < N; ++i) {
        temp = originTable[i] - originTable[i-1];
        distanceTable.push_back(temp);
    }
}

bool isItOkay(int value) {
    int cnt = 1;
    int sums = 0;
    for(int target : distanceTable) {
        sums += target;
        if(sums >= value) {
            cnt++;  sums = 0;
            if(cnt >= C)    return true;
        }

    }

    return false;
}

int binarySearch() {
    int answer;
    int s,e,mid;    s = 0;  e = *max_element(originTable.begin(), originTable.end());   mid = (s + e) / 2;
    if(C == 2) {
        return *(originTable.end() - 1) - originTable[0];
    } else if(N == C) {
        return *min_element(distanceTable.begin(), distanceTable.end());
    }

    
    // cout << s << " " << mid << " " << e << endl;
    while(mid < e) {
        if(isItOkay(mid)) {
            answer = mid;
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = (s + e) / 2;
        // cout << s << " " << mid << " " << e << endl;
    }
    return answer;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    cout << binarySearch();


    return 0;
}