#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int w,h;
vector<vector<vector<bool>>> visited;
vector<vector<int>> map;

struct point{
    int y, x, dir, cnt;
};
queue<point> que;

void input() {
    int i,j;
    char temp;
    cin >> w >> h;
    map.resize(h, vector<int>(w, 0));
    for(i = 0; i < h; ++i) {
        cin.get(temp);
        for(j = 0; j < w; ++j) {
            cin.get(temp);
            if(temp == '.') map[i][j] = 0;
            else if (temp == '*') map[i][j] = 1;
            else {
                map[i][j] = 2;
                //여기서 start, goal 받고
            }
        }
    }
}

void printMap() {
    int i,j;
    for(i = 0; i < h; ++i) {
        for(j = 0; j < w; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    input();
    printMap();

}
