#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> table;
vector<int> inDegree;
vector<bool> visited;

struct cmp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

void init() {
    int a,b;
    cin >> N >> M;
    table.resize(N+1);
    inDegree.resize(N+1, 0);
    visited.resize(N+1, false);
    

    for(int i = 0; i < M; ++i) {
        cin >> a >> b;
        table[a].push_back(b);
        
        inDegree[b]+=1;
    }

    priority_queue<int, vector<int>, cmp> pq;

    for(int i = 1; i < N+1; ++i) {
        if(inDegree[i] == 0) {
            pq.push(i);
        }
    }

    int curr, next;
    curr = pq.top();  pq.pop();
    while(!pq.empty()) {
        next = pq.top();    pq.pop();
        table[curr].push_back(next);
        inDegree[next] += 1;
        curr = next;
    }

}

void printTable() {
    cout << "visited : " << endl;
    for(int i = 1; i < N+1; ++i) {
        cout << visited[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "inDegrees : " << endl;
    for(int i = 1; i < N+1; ++i) {
        cout << inDegree[i] << " ";
    }
    cout << endl;
    
    cout << "table : " << endl;
    for(int i = 1; i < N+1; ++i) {
        if(table[i].empty())    cout << "empty!";
        else {
            for(int j :table[i]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    init();

    priority_queue<int, vector<int>, cmp> pq;
    for(int i = 1; i < N+1; ++i) {
        if(inDegree[i] == 0) {
            pq.push(i);
            visited[i] = true;
        }
    }

    // printTable();

    while(!pq.empty()) {
        int curr = pq.top();    pq.pop();
        cout << curr << " ";
        for(int next : table[curr]) {
            if(inDegree[next] == 1) {
                inDegree[next] -= 1;
                pq.push(next);
                visited[next] = true;
            } else {
                inDegree[next] -= 1;
            }
        }
    }

    return 0;
}