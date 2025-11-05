#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int width, height;
string targetA;
string targetB;
vector<vector<int>> DP;

void init() {
    cin >> targetA >> targetB;
    width = targetA.size();
    height = targetB.size();

    DP.resize(height, vector<int>(width, 0));
}

void findDP() {
    for(int i = 0; i < width; ++i) {
        if(targetA[i] == targetB[0]) {
            DP[0][i] = 1;
        } else {
            if(i == 0)      DP[0][0] = 0;
            else            DP[0][i] = DP[0][i-1];
        }
    }

    for(int j = 1; j < height; ++j) {
        for(int i = 0; i < width; ++i) {
            if(targetA[i] == targetB[j]) {
                if(i == 0)  DP[j][0] = 1;
                else        DP[j][i] = DP[j-1][i-1] + 1;
            }
            else {
                if(i == 0)  DP[j][0] = DP[j-1][0];
                else DP[j][i] = max(DP[j][i-1], DP[j-1][i]);
            }

        }
    }
}

int findMax() {
    int result = 0;
    for(vector<int> arr : DP) {
        for(int arr_ele : arr) {
            if(arr_ele > result)    result = arr_ele;
        }
    }

    return result;
}

void printTable() {
    int result = 0;
    for(vector<int> arr : DP) {
        for(int arr_ele : arr) {
            cout << arr_ele << " ";
        }
        cout << endl;
    }

    // return result;
}

int main() {

    init();
    findDP();

    cout << findMax();
    // printTable();

    return 0;
}