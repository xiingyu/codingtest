#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> table;
vector<int> ansArr;
vector<int> indexTable;


void init() {
    cin >> N;

    int temp;
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }

    indexTable.assign(N, 0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();

    int temp;   int idx = 1;    int idxTemp = 0;
    ansArr.push_back(table[0]);
    for(int i = 1; i < N; ++i) {
        temp = table[i];
        if(temp > ansArr[idx - 1]) {
            ansArr.push_back(temp);
            indexTable[i] = idx;
            idx++;
        } else {
            idxTemp = lower_bound(ansArr.begin(), ansArr.begin() + idx, temp) - ansArr.begin();
            ansArr[idxTemp] = temp;
            indexTable[i] = idxTemp;
        }
    }

    vector<int> decodeTable;

    cout << idx << '\n';
    for(int i = N - 1; i >= 0; --i) {
        if(indexTable[i] == idx - 1) {
            decodeTable.push_back(table[i]);
            --idx;
        }
    }

    for(int i = (int)decodeTable.size() - 1; i >= 0; --i) {
        cout << decodeTable[i] << ' ';
    }




    return 0;
}