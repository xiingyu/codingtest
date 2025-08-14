#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int odds[] = {2,3,5,7};
int innerOdds[] = {1, 3, 5, 7, 9};
vector<int>results;

void init() {
    cin >> N;
}

bool isItOdd(const int& target) {
    int sqrted = sqrt(target);
    // if(target == 233)   cout << sqrted << endl;
    for(int i = 2; i <= sqrted; ++i) {
        if(target % i == 0) {
            return false;
        }
    }
    // if(target == 233)   cout << "return true" << endl;
    return true;
}

void dfs(int number, int depth) {
    int makeNumber = 0;
    if(depth >= N) {
        if(isItOdd(number)) { 
            results.push_back(number);
        }
        return;
    }
    // if(number > 2330 && number < 2340) cout << " " << number << endl;
    // cout << number << " " << depth << endl;
    // if(isItOdd(number)) {
        for(int i : innerOdds) {
        // cout << to_string(number) + to_string(i)  << " " << depth<< endl;
            makeNumber = number * 10 + i;
            if(isItOdd(makeNumber)) {
                dfs(makeNumber, depth+1);
            }
        }
    // }
}
void printResult() {
    for(int i = 0; i < results.size(); ++i) {
        cout << results[i] << "\n";
    }
    cout << endl;

}

int main() {
    init();
    for(int i : odds) {
        dfs(i, 1);
    }
    printResult();

    return 0;
}