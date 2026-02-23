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
        } else {
            return me < other.me;
        }
    }
};
vector<polls> A;
vector<int> table;
vector<int> ansArr;
vector<int> idxArr; 

void init() {
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i].me >> A[i].to;
    }
    sort(A.begin(), A.end());

    for(int i = 0; i < N; ++i) {
        table.push_back(A[i].to);
    }

    idxArr.resize(N, 0);

}

void LISLogic() {
    int idx = 1; int temp = 0; int localTemp = 0;

    ansArr.push_back(table[0]);
    temp = table[0];

    for(int i = 1; i < N; ++i) {
        temp = table[i];
        if(temp > ansArr[idx-1]) {
            ansArr.push_back(temp);
            idxArr[i] = idx;
            idx++;
        } else {
            localTemp = lower_bound(ansArr.begin(), ansArr.begin() + idx, temp) - ansArr.begin();
            ansArr[localTemp] = temp;
            idxArr[i] = localTemp;
        }
    }
}
void printTable(const vector<int>& ansIndex) {
    for(int i = 0; i < ansArr.size(); ++i) {
        cout << ansArr[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N; ++i) {
        cout << table[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < idxArr.size(); ++i) {
        cout << idxArr[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < ansIndex.size(); ++i) {
        cout << ansIndex[i] << ' ';
    }
    cout << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    LISLogic();
    

    vector<int> ansIndex;
    int tempIdx = ansArr.size() - 1;
    for(int i = N-1; i >= 0; --i) {
        if(idxArr[i] == tempIdx) {
            ansIndex.push_back(i);
            tempIdx--;
        }
        if(tempIdx < 0) break;
    }

    tempIdx = (int)ansIndex.size();
    // cout << tempIdx << endl << endl;;
    cout << N - tempIdx << '\n';
    tempIdx--;
    // printTable(ansIndex);


    for(int i = 0; i < N; ++i) {
        polls target = A[i];

        if(ansIndex[tempIdx] == i) {
            tempIdx--;
        } else {
            cout << target.me << '\n';
        }
    }
        


    return 0;
}