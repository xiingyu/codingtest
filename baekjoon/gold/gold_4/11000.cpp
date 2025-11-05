#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
struct lacture{
    int s,e;
};
vector<lacture> lactures;
priority_queue<int, vector<int>, greater<int>> PQ;

auto cmp(const lacture& a, const lacture&b) {
    if(a.s < b.s)   return true;
    else if(a.s == b.s && (a.e < b.e)) {
        return true;
    }
    else return false;
}

void init() {
    int temps, tempe;
    cin >> N;
    while(N--) {
        cin >> temps >> tempe;
        lactures.push_back(lacture{temps, tempe});
    }

    sort(lactures.begin(), lactures.end(), cmp);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    init();
    
    PQ.push(0);
    for(lacture target : lactures) {
        if(target.s >= PQ.top()) {
            PQ.pop();
            PQ.push(target.e);
        } else {
            PQ.push(target.e);
        }
    }

    cout << PQ.size();

    return 0;
}