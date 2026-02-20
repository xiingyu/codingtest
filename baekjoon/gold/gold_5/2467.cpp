#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int N;
vector<int> table;

void init() {
    cin >> N;
    int temp;
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        table.push_back(temp);
    }

}



int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int st = 0; int ed = N-1;
    ll minimum = (2e9) + 1;
    ll temp;
    int mem1 = 0; int mem2 = 0;

    while(st < ed) {
        temp = table[st] + table[ed];
        if(abs(temp) < minimum) {
            mem1 = st;
            mem2 = ed;
            minimum = abs(temp);
        }
        if(temp < 0) st++;
        else         ed--;


    }

    cout << table[mem1] << " " << table[mem2];



    return 0;
}