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
    
    init();


    return 0;
}