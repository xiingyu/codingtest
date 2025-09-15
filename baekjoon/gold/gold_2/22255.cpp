#include <iostream>
#include <vector>
#include <queue>
#define MAX 1e9
using namespace std;

int dy[] = {-1, 1, 0, 0, -1, 1, 0, 0};  // 0 1 2 each 0123, 45, 67
int dx[] = {0, 0, 1, -1, 0, 0, 1, -1};

struct Qpoint {
    int y,x;
    int turn;
    int cost;
};

struct point {
    int y,x;
};

int N,M;
point start, goal;
vector<vector<int>> table;
vector<vector<vector<int>>> costTable;

auto cmp = [](const Qpoint& a, const Qpoint& b) {
    return a.cost > b.cost;
};

void init() {
    int tempy,tempx, temp;
    cin >> N >> M;

    cin >> tempy >> tempx;  start = point{tempy,tempx};
    cin >> tempy >> tempx;  goal = point{tempy,tempx};

    table.resize(N+2, vector<int>(M+2, -1));
    costTable.resize(N+2, vector<vector<int>>(M+2, vector<int>(3, MAX)));

    for(int i = 0; i <= N+1; ++i) {
        for(int j = 0; j <= M+1; ++j) {
            if(i == 0 || i == N+1 || j == 0 || j == M+1)  continue;
            else{
                cin >> temp;

                table[i][j] = temp;
            }
            
        }
    }
}

int dijkstra() {
    priority_queue<Qpoint, vector<Qpoint>, decltype(cmp)> PQ(cmp);

    PQ.push(Qpoint{start.y, start.x, 0, table[start.y][start.x]});

    while(!PQ.empty()) {
        Qpoint curr = PQ.top(); PQ.pop();

        if(curr.y == goal.y && curr.x == goal.x) return curr.cost;

        int nx, ny, ncost, i;
        int nturn = curr.turn + 1;

        int s,e;
        int mod = nturn % 3;

        if(mod == 0) {
            s = 0;  e = 4;

        } else if(mod == 1) {
            s = 4;  e = 6;

        } else if(mod == 2) {
            s = 6;  e = 8;
        }

        
        for(i = s; i < e; ++i) {
            ny = curr.y + dy[i];
            nx = curr.x + dx[i];
            ncost = table[ny][nx];

            if(ncost == -1) continue;
            if(costTable[ny][nx][mod] <= curr.cost + ncost) continue;
            costTable[ny][nx][mod] = curr.cost + ncost;
            PQ.push(Qpoint{ny,nx, nturn, curr.cost + ncost});
        }


    }



    return -1;
}

void printTable() {
    
    for(int i = 0; i <= N+1; ++i) {
        for(int j = 0; j <= M+1; ++j) {
            cout << table[i][j] << " ";
            
        }
        cout << endl;
    }
}


int main() {
    init();
    // printTable();
    cout << dijkstra();

    return 0;
}