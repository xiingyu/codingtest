#include <iostream>
#include <vector>
#include <queue>
// #include <map>
#include <algorithm>
#define MAX 1e9
using namespace std;

int N;
int minimum = MAX;
vector<vector<int>> table;
struct node {
    int depth;
    int color;
    int cost;
};

void init() {
    int R,G,B;
    cin >> N;

    table.resize(N, vector<int>(3, MAX));

    for(int i = 0; i < N; ++i) {
        cin >> R >> G >> B;
        table[i][0] = R;
        table[i][1] = G;
        table[i][2] = B;

    }

}

// void bfs() {
//     queue<node> que;
//     for(int i = 0; i < 3; ++i) {
//         que.push(node{0,i,table[0][i]});
//     }

//     while(!que.empty()) {
//         node curr = que.front();    que.pop();
//         if(curr.depth >= N-1) {
//             minimum = min(minimum, curr.cost);
//             continue;
//         }

//         node next;
//         next.depth = curr.depth + 1;
//         for(int i = 0; i < 3; ++i) {
//             if(i == curr.color)   continue;
//             next.cost = curr.cost + table[next.depth][i];
//             next.color = i;

//             if(next.cost > minimum) continue;
//             que.push(next);
//         }

//     }

// }

bool cmp(const node&a, const node&b) {
    return a.cost > b.cost;
}

void bfs() {
    priority_queue<node, vector<node>, decltype(&cmp)> que(cmp);
    // queue<node> que;
    for(int i = 0; i < 3; ++i) {
        que.push(node{0,i,table[0][i]});
    }

    while(!que.empty()) {
        node curr = que.top();    que.pop();
        if(curr.depth >= N-1) {
            minimum = min(minimum, curr.cost);
            return;
        }

        node next;
        next.depth = curr.depth + 1;
        for(int i = 0; i < 3; ++i) {
            if(i == curr.color)   continue;
            next.cost = curr.cost + table[next.depth][i];
            next.color = i;

            if(next.cost > minimum) continue;
            que.push(next);
        }

    }

}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << table[i][j] << " " ;
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    bfs();

    cout << minimum;

    return 0;
}