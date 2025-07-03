#include <iostream>
#include <vector>
using namespace std;

int n,d;
vector<int> dp;

struct Point {
    int s, e, c;
};
vector<Point> ways;

int findMin(int a, int b) { return a < b ? a : b;}

void input() {
    int i, temp0, temp1, temp2;
    for(i = 0; i < n; ++i) {
        cin >> temp0 >> temp1 >> temp2;
        ways.push_back(Point{temp0, temp1, temp2});
    }
    for(i = 0; i <= d; ++i){
        dp.push_back(i);
    }
}

void search() {
    int i, target;
    int dis = 1;
    int temp_dis;
    Point point;

    for(i = 1; i <= d; ++i){
        dp[i] = dp[i-1]+1;
        for(target = 0 ; target < ways.size(); ++target) {
            point = ways[target];
            if(point.e == i) {
                temp_dis = findMin(dp[i], dp[point.s] + point.c);
                dp[i] = findMin(dp[i], temp_dis);
            }
              
        }
    }
}

void printMap() {
    for(int i = 0 ; i <= d ; ++i) {
        cout << dp[i] << " ";
    }
}

int main(void) {
    cin >> n>>d;
    // dp.resize(d+1);
    input();
    search();
    // printMap();

    cout << dp[d] << endl;

}