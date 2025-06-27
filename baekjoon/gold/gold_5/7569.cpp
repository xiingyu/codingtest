#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> table;
int m,n,h;

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
    // print_table();
    

    


}