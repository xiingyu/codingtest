#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;


auto cmpLower = [](const int& a, const int& b) {
    return a > b;
};

auto cmpUpper = [](const int& a, const int& b) {
    return a < b;
};
priority_queue<int, vector<int>, decltype(cmpLower)> LowPQ(cmpLower);
priority_queue<int, vector<int>, decltype(cmpUpper)> HighPQ(cmpUpper);

void logic() {
    int i, temp;
    cin >> N;

    for(i = 1; i <= N; ++i) {
        cin >> temp;

        if(i == 1) {
            HighPQ.push(temp);
            secondPendingInt = temp;
            cout << temp << "\n";
        }
        else if(i == 2) {
            if (temp > secondPendingInt) {
                HighPQ.push(temp);
                LowPQ.push(secondPendingInt);
            } else {
                HighPQ.push(secondPendingInt);
                LowPQ.push(temp);
            }
            cout << HighPQ.top() << "\n";
        }
        else if(i % 2 == 0) {
            if(temp >= LowPQ.top()) {

            }

        } 
        else {

        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}
