/// 이건 그냥 2중 for문. 실용성만 있지 효용성은 제로. 앞으로 binary search로 하도록
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct polls{
    int my;
    int to;

    bool operator<(const polls& other) {
        if(my == other.my) {
            return to < other.to;
        } else {
            return my < other.my;
        }
    }
};
vector<polls> A;
vector<int> Barr;
vector<int> dp;

void init() {
    polls temp;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> temp.my >> temp.to;
        A.push_back(temp);
    }

    sort(A.begin(), A.end());
    for(int i = 0; i < N; ++i) {
        polls curr = A[i];
        Barr.push_back(curr.to);
    }

    dp.assign(510, 1);
}

void DPLogic() {
    for(int i = 1; i < N; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(Barr[i] > Barr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        cout << A[i].my << " ";
    }
    cout << endl;
    for(int i = 0; i < N; ++i) {
        cout << A[i].to << " ";
    }
    cout << endl;
}

int main() {
    init();
    DPLogic();
    // printTable();

    cout << N - (*max_element(dp.begin(), dp.end()));


    return 0;
}