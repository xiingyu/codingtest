#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> table;

void init() {
    int temp;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }

}

int main() {
    init();

    int i,j, temp;
    int result = 1e9;
    int target1, target2;
    
    for(i = 0; i < N-1; ++i) {
        for(j = i+1; j < N; ++j) {
            temp = abs(table[i]+table[j]);
            if(temp < result) {
                // cout << i << " " << j << " " << temp << endl;
                result = temp;
                target1 = table[i]; target2 = table[j];
            }
        }
    }

    cout << target1 << " " << target2 << endl;

    return 0;
}