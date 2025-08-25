#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;


// bool cmp (const int& a, const int& b) {
//     return a > b;
// }
auto cmp = [](const int& a, const int& b) {
    return a > b;
};
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int temp;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> temp;
        pq.push(temp);
    }
}

int prioQ() {
    int result = 0;
    while((int)pq.size() > 1) {
        int f,s;
        f = pq.top();   pq.pop();
        s = pq.top();   pq.pop();

        result += f+s;
        pq.push(f+s);
    }


    return result;
}

int main() {
    init();
    int result = prioQ();

    cout << result;

    return 0;

}