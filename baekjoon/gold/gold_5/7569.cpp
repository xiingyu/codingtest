#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<vector<int>>> table;
vector<vector<vector<bool>>> visited;
int m,n,h;

int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dh[] = {-1, 1, 0, 0, 0, 0};

typedef struct _target {
    int x,y,z;
    target(int z, int y, int x) : x(x), y(y), z(z) {}  // 생성자 추가
}target;
queue<target>que;

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

int dpeth_cnt(int depth) {
    // if (is_all_check(visited) == false && )
    int i,j,k;
    int temp;
    for(i =0; i < h; ++i) {
        table[i].resize(n);
        for(j =0; j < n; ++j) {
            table[i][j].resize(m);
            for(k =0; k < m; ++k) {
                if (table[i][j][k] == 1) {
                    que.push({i,j,k});
                }
            }
        }
    }




}


void bfs() {

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
    

    


}