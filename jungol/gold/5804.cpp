#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum {
    TREE_EMPTY,
    TREE_PICK
};

int N,C, maxHouse;
vector<int> houses;
vector<int> road;
vector<int> pickedIndex;

void init() {
    int temp;
    cin >> N >> C;

    for(int i = 0; i < C; ++i) {
        cin >> temp;
        houses.push_back(temp);
    }
    sort(houses.begin(), houses.end());
    maxHouse = houses[C - 1];

    road.resize(maxHouse+1, TREE_EMPTY);

    road[houses[0]] = TREE_PICK;
    road[houses[C - 1]] = TREE_PICK;
    pickedIndex.push_back(0);
    pickedIndex.push_back(C-1);
}

int binarySearch(int target, int start, int end) {  //tartget is value, start&end are index
    int mid;
    int left = houses[start];
    int right = houses[end];

    while(left <= right) {
        mid = (start + end) / 2;
        if(houses[mid] == target) {
            return mid;
        } else if (houses[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return (abs(houses[left] - target) < abs(houses[right] - target)) ? left: right;
}

void logic() {


}

int main() {
    init();
    if(C == 2) {
        cout << houses[1] - houses[0];
        return 0;
    } else {
        logic();
    }

}