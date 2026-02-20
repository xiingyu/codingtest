///이분탐색을 이용한 LIS. 근데 복원은 곁들이지 않은.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct polls {
    int me;
    int to;

    bool operator<(const polls& other) {
        if(me == other.me) {
            return to < other.to;
        }
        else {
            return me < other.me;
        }
    }
};
vector<polls> A;
vector<int> BTable;

void init() {
    cin >> N;
    
    polls temp;
    for(int i = 0; i < N; ++i) {
        cin >> temp.me >> temp.to;
        A.push_back(temp);
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < N; ++i) {
        BTable.push_back(A[i].to);
    }

}


int main() {
    init();

    int temp = 0;   int idx = 0;
    vector<int> ansArr;
    ansArr.push_back(BTable[0]);
    idx++;  

    for(int i = 1; i < N; ++i) {
        temp = BTable[i];
        if(temp > ansArr[idx-1]) {
            ansArr.push_back(temp);
            idx++;
        } else {
            ansArr[lower_bound(ansArr.begin(), ansArr.begin() + idx, temp) - ansArr.begin()] = temp;
        }
    }
    cout << N - idx;


    return 0;
}