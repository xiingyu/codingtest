#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R,C;

vector<vector<int>> table;
vector<vector<bool>> visited;
struct point {
    int y, x, cost;
};

auto cmp = [](const point& a, const point& b) {
    return a.cost > b.cost;
};

// 0 . 1 x 2 L
void init() {
    cin >> R >> C;

    table.resize(R, vector<int>(C, 0));
    for(int i = 0; i < R; ++i) {
        string temp;
        cin >> temp;


    }


}



int main() {


    return 0;
}