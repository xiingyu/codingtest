#include <iostream>
#include <vector>
using namespace std;

int N,M;
int minimum = 1e9;
int cCount = 0;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

struct cctv {
    int type;
    int y,x;
    int rotation;
};
struct point {
    int y,x;
};
vector<cctv> cctvs;
vector<vector<int>> table;

/// wall is 9 ///
void init() {
    int temp;
    cin >> N >> M;
    
    table.resize(N, vector<int>(M, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> temp;
            table[i][j] = temp;
            if(temp>= 1 && temp <= 5) {
                cctvs.push_back(cctv{temp, i, j, 0});
            }

        }
    }

    cCount = cctvs.size();
}

int countBlacks() {
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 0)   
                cnt++;
        }
    }
    return cnt;
}

int culRotate(const int& i) {
    if(i < 0)   return i+4;
    else if(i >= 4)     return i-4;
    else return i;
}

void brushOrClear(cctv target, int flag) {   //true is bush,, false is clear;
    point next;
    while(true) {
        // vector<point> nexts;
        
        next.y = target.y + dy[target.rotation];
        next.x = target.x + dx[target.rotation];
        // nexts.push_back(next);
        
        // if(target.type == 2) {
        //     next.y = target.y + dy[culRotate(target.rotation + 2)];
        //     next.x = target.x + dx[culRotate(target.rotation + 2)];
        //     nexts.push_back(next);
            
        // } else if(target.type == 3) {
        //     next.y = target.y + dy[culRotate(target.rotation + 1)];
        //     next.x = target.x + dx[culRotate(target.rotation + 1)];
        //     nexts.push_back(next);
            
        // } else if(target.type == 4) {
        //     next.y = target.y + dy[culRotate(target.rotation + 1)];
        //     next.x = target.x + dx[culRotate(target.rotation + 1)];
        //     nexts.push_back(next);
        //     next.y = target.y + dy[culRotate(target.rotation - 1)];
        //     next.x = target.x + dx[culRotate(target.rotation - 1)];
        //     nexts.push_back(next);
            
        // }
        if(next.y < 0 || next.x < 0 || next.x >= M || next.y >=N)   break;
        if(table[next.y][next.x] == 6)  break;

        int number = table[next.y][next.x];
        if(flag) {
            if(number <= 0) table[next.y][next.x] -= 1;
            else    table[next.y][next.x] = number;
        } else {
            if(number < 0) table[next.y][next.x] += 1;
            else    table[next.y][next.x] = number;

        }

        
        // table[next.y][next.x] = flag ? ((table[next.y][next.x] == 0) ? 9 : table[next.y][next.x] = table[next.y][next.x]) : (table[next.y][next.x] == 9 ? 0 : table[next.y][next.x]);
        target.y = next.y;  target.x = next.x;
    }
}

void printTable() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int depth) {
    if(depth >= cCount) {
        minimum = min(countBlacks(), minimum);
        // printTable();
        // cout << endl;
        return;
    }
    
    cctv curr = cctvs[depth];
    if(curr.type == 2) {
        for(int i = 0; i < 2; ++i) {
            curr.rotation = culRotate(curr.rotation + i);
            brushOrClear(curr, true);
            brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 2)}, true);

            dfs(depth + 1);

            brushOrClear(curr, false);
            brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 2)}, false);

        }
    } else {
        for(int i = 0; i < 4; ++i) {
            
            curr.rotation = culRotate(curr.rotation + 1);
            brushOrClear(curr, true);
            if(curr.type == 1) {
                dfs(depth + 1);

            } else if(curr.type == 3) {
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 1)}, true);

                dfs(depth + 1);
                
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 1)}, false);

            } else if(curr.type == 4) {
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 1)}, true);
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation - 1)}, true);

                dfs(depth + 1);
                
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 1)}, false);
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation - 1)}, false);

            } else if(curr.type == 5) {
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 2)}, true);
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 1)}, true);
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation - 1)}, true);

                dfs(depth + 1);
                
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 2)}, false);
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation + 1)}, false);
                brushOrClear(cctv{curr.type, curr.y, curr.x, culRotate(curr.rotation - 1)}, false);

            }
            brushOrClear(curr, false);
        }
        // printTable();
        // cout << " ?? " << endl;
    }

}



int main() {
    init();
    dfs(0);
    // printTable();
    cout << minimum;


    // cout << cctvs[0].type;

    return 0;
}