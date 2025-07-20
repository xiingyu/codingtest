#include <iostream>
#include <vector>
using namespace std;
int n;
bool oddEven = false; // false goes to down
int rate = 1;

enum {RIGHT, LEFTDOWN, DOWN, RIGHTUP};
int dx[] = {1, -1, 0, 1};
int dy[] = {0, 1, 1, -1};

struct point {
    int y,x;
};
vector<vector<point>> map;

void initial() {
    int i, j;
    cin >> n;
    map.resize(1001, vector<point>(1001, point{0, 0}));
    for(i = 1; i <= 1000; ++i) {
        for(j = 1; j <= 1000; ++j) {
            map[i][j] = point{i,j};
        }
    }


}

point logic() {
    --n;
    int cmd = 0;
    int maxCmd = 4;
    point target = {1,1};
    int cx, cy;
    while(n) {
        cx = target.x;
        cy = target.y;
        if(cmd == maxCmd) cmd = 0;

        if(cmd == LEFTDOWN || cmd == RIGHTUP) {

            for(int i = 0; i < rate; ++i) {
                target = point{target.y + dy[cmd], target.x + dx[cmd]};
                --n;
                if(n <= 0) return target;
                // cout << "cmd : " << cmd << " y : " << target.y << " x : " << target.x << endl;
            }
            rate += 1;
        }   
        else {
            target = point{cy + dy[cmd], cx + dx[cmd]};
            --n;
            
        }
        if(n <= 0) return target;

        // cout << "cmd : " << cmd << " rate : " << rate << " y : " << target.y << " x : " << target.x << endl;
        cmd += 1;
        
    }
    return target;
}

int main(){
    initial();
    point result;
    if(n == 1) result = map[1][1];
    else result = logic();
    cout << result.y << "/" << result.x << endl;


}
