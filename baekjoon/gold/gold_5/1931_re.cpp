#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt = 0;
struct times {
    unsigned int s,e;
};

queue<times> table;
vector<times> vTable;

void init() {
    unsigned int s,e;
    int N;
    cin >> N;

    while(N--) {
        cin >> s >> e;
        vTable.push_back(times{s,e});
    }

    sort(vTable.begin(), vTable.end(), [](const times a, const times b){
        if(a.e < b.e) return true;
        else if(a.e == b.e){
            return a.s < b.s;
        } else return false;
        //return (a.e < b.e) || (a.e == b.e && a.s < b.s);
    });

}

void counts() {

    unsigned int curr_time = 0;

    for(times curr : vTable) {
        if(curr.s < curr_time)  continue;
        // cout << curr.s << " " << curr.e << endl;
        curr_time = curr.e;
        cnt++;

    }

}

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    counts();

    cout << cnt << endl;
    return 0;
}