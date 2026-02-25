#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dy[] = {0, 0, -1 ,1};
int dx[] = {-1, 1, 0 ,0};

int N,M;
int name = 0;
vector<vector<int>> ans;
vector<vector<int>> table;
struct point{
    int y,x;
};
struct ID{
    int name,value;
};
vector<vector<ID>> dp;
vector<vector<bool>> visited;

void init() {
    string s;
    cin >> N >> M;

    table.resize(N, vector<int>(M, 0));
    ans.resize(N, vector<int>(M, 0));
    dp.resize(N, vector<ID>(M, ID{0,0}));
    visited.resize(N, vector<bool>(M, false));
    for(int i = 0; i < N; ++i) {
        cin >> s;
        for(int j = 0; j < M; ++j) {
            table[i][j] = (int)(s[j] - '0');
        }
    }
}

void fillBFS(const point& target) {
    name++;
    int cnt = 1;
    queue<point> foundTarget;
    queue<point> candidate;

    candidate.push(target);
    foundTarget.push(target);
    visited[target.y][target.x] = true;

    while(!candidate.empty()) {
        point curr = candidate.front(); candidate.pop();

        for(int i = 0; i < 4; ++i) {
            point next = {curr.y + dy[i], curr.x + dx[i]};
            if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= M) continue;
            if(visited[next.y][next.x]) continue;
            if(table[next.y][next.x] == 1) continue;

            visited[next.y][next.x] = true;
            foundTarget.push(next);
            candidate.push(next);
            cnt++;
        }
    }
    // cout << "queue size : " << foundTarget.size() << endl;
    while(!foundTarget.empty()) {
        point curr = foundTarget.front();   foundTarget.pop();
        dp[curr.y][curr.x] = ID{name, cnt};
    }


}

void fillZeros() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 0 && visited[i][j] == false) {
                // cout << i << " " << j << endl;
                fillBFS(point{i,j});
            }
        }
    }
}

bool checkID(const int& target, const vector<int>& ids) {
    if(ids.empty()) return true;
    else {
        for(int i = 0; i < (int)ids.size(); ++i) {
            if(target == ids[i]) return false;
        }
    }
    return true;
}

void scan() {
    point next;
    vector<int> ids;
    int cnt = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 1) {
                ids.clear();
                cnt = 1;
                for(int k = 0; k < 4; ++k) {
                    next.y = i + dy[k];
                    next.x = j + dx[k];
                    if(next.y < 0 || next.x < 0 || next.y >= N || next.x >= M) continue;
                    ID temp = dp[next.y][next.x];
                    if(checkID(temp.name, ids)) {
                        cnt += temp.value;
                        ids.push_back(temp.name);
                    }
                }
                ans[i][j] = cnt % 10;
            }
        }
    }
}
// void printTable() {
//     for(int i = 0; i < N; ++i) {
//         for(int j = 0; j < M; ++j) {
//             cout << dp[i][j];
//         }
//         cout << '\n';
//     }
//     cout << endl;
//     for(int i = 0; i < N; ++i) {
//         for(int j = 0; j < M; ++j) {
//             cout << table[i][j];
//         }
//         cout << '\n';
//     }
//     cout << endl;

// }

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    fillZeros();
    scan();

    // printTable();

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}