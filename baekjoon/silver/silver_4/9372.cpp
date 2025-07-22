#include <iostream>
#include <vector>
using namespace std;

int T,N,M;
vector<int> parent;
vector<int> MST;

struct point {
    int start, end;
};
vector<point> flights;

void init() {
    int i, s, e;
    cin >> N >> M;
    parent.assign(N+1,0);
    MST.clear();
    flights.clear();
    for(i = 1; i <= M; ++i) {
        cin >> s >> e;
        flights.push_back(point{s,e});
    }
    for(int j = 1; j <= N; ++j) parent[j] = j;
}

int findRoot(int target) {
    if(parent[target] == target) return target;
    return findRoot(parent[target]);

}

void setRoot(int a, int b) {
    int x = findRoot(a);
    int y = findRoot(b);
    if(x != y) parent[y] = a;
}

void findMST() {
    int i;

    for(i = 0; i < flights.size(); ++i) {
        point curr = flights[i];

        if(findRoot(curr.start) == findRoot(curr.end)) continue;
        else {
            MST.push_back(i);
            setRoot(curr.start, curr.end);
        }
    }
}


int main() {
    cin >> T;
    
    for(int i = 0; i < T; ++i) {
        init();
        // cout << "init finish" << endl;
        // cout << flights.size() << endl;
        // cout << MST.size() << endl;

        findMST();
        // cout << "findMST finish" << endl;
        cout << MST.size() << endl;
    }


}