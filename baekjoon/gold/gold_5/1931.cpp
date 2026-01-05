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

void init() {
    unsigned int s,e;
    int N;
    vector<times> vTable;
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

    for(int i = 0; i < (int)vTable.size(); ++i) {
        table.push(vTable[i]);
    }
    
    // for(int i = 0; i < vTable.size(); ++i) {
    //     cout << vTable[i].s << " " << vTable[i].e << endl;
    // }
}

void counts() {

    unsigned int curr_time = 0;

    while(!table.empty()) {
        times curr = table.front(); table.pop();
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