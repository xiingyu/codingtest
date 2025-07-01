#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<vector<int>>> table;
vector<vector<vector<bool>>> visited;
int m,n,h;

int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {-1, 1, 0, 0, 0, 0};

typedef struct _target {
    int x,y,z;
    // target(int z, int y, int x) : x(x), y(y), z(z) {}  // 생성자 추가
}target;
bool que_flag = false;
queue<target>que0;
queue<target>que1;


void bfs();
bool is_all_check(const vector<vector<vector<bool>>>& arr) {
    int i,j,k;
    int temp;
    for(i =0; i < h; ++i) {
        table[i].resize(n);
        for(j =0; j < n; ++j) {
            table[i][j].resize(m);
            for(k =0; k < m; ++k) {
                if (arr[i][j][k] == false) return false;
            }
        }
    }

    return true;
}

void get_table() {
    int i,j,k;
    int temp;
    table.resize(h);
    for(i =0; i < h; ++i) {
        table[i].resize(n);
        for(j =0; j < n; ++j) {
            table[i][j].resize(m);
            for(k =0; k < m; ++k) {
                cin >> temp;
                table[i][j][k] = temp;
            }
        }
    }
}

int depth_cnt(int depth) {
    // if (is_all_check(visited) == false && )
    if(is_all_check(visited) == true) return depth;
    else if (is_all_check(visited) == false && que0.empty() && que1.empty()) return -1;
    int i,j,k;
    int temp;
    for(i =0; i < h; ++i) {
        table[i].resize(n);
        for(j =0; j < n; ++j) {
            table[i][j].resize(m);
            for(k =0; k < m; ++k) {
                if (table[i][j][k] == 1 && visited[i][j][k] == false) {
                    if(que_flag) que1.push({i,j,k});
                    else que0.push({i,j,k});
                }
                else if (table[i][j][k] == -1) {
                    visited[i][j][k] = true;
                }
            }
        }
    }
    bfs();
    return depth_cnt(depth +1);
}


void bfs() {
    target curr = {0,0,0};

    while(que_flag ? !que1.empty() : !que0.empty()) {
        
        if (que_flag) {
            curr = que1.front();
            que1.pop();
        }
        else  {
            curr = que0.front(); 
            que0.pop();
        }
        int cc0 = curr.x, cc1 = curr.y, cc2 = curr.z;   //means, current cordinates.
        visited[cc0][cc1][cc2] = true;

        for (int i = 0; i < 6; ++i) {
            if (((cc0 + dx[i])>=h || (cc0 + dx[i])<0) || ((cc1 + dy[i])>=n || (cc1 + dy[i])<0) || ((cc2 + dz[i])>=m || (cc2 + dz[i])<0)) {
                continue;
            }
            int fut_x = cc0 + dx[i], fut_y = cc1 + dy[i], fut_z = cc2 + dz[i];

            if(visited[fut_x][fut_y][fut_z] == true) {
                continue;
            }
            
            if (que_flag) que0.push({fut_x, fut_y, fut_z});
            else que1.push({fut_x, fut_y, fut_z});

            
        }
        
    }
    que_flag = !que_flag;
}

void initializer() {
    int i,j,k;
    int temp;
    for(i =0; i < h; ++i) {
        table[i].resize(n);
        for(j =0; j < n; ++j) {
            table[i][j].resize(m);
            for(k =0; k < m; ++k) {
                visited[i][j][k] = false;
            }
        }
    }

}

void print_table() {
    int i,j,k;
    for(i =0; i < h; ++i) {
        for(j =0; j < n; ++j) {
            for(k =0; k < m; ++k) {
                cout << table[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


int main(void) {


    cin >> m >> n >> h;
    get_table();
    initializer();
    // print_table();
    cout << depth_cnt(1) << endl;
    

    


}