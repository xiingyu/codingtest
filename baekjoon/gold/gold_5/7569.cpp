#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> table;
int m,n,h;

void get_table() {
    int i,j,k;
    int temp;
    table.resize(h+2);
    for(i =0; i < m; ++i) {
        table[i].resize(m+2);
        for(j =0; j < h; ++j) {
            table[i][j].resize(k+2);
            for(k =0; k < n; ++k) {
                cin >> temp;
                table[i][j][k] = temp;
            }
        }
    }
}

void print_table() {
    int i,j,k;
    for(i =0; i < m; ++i) {
        for(j =0; j < h; ++j) {
            for(k =0; k < n; ++k) {
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
    print_table();

    


}