#include <iostream>
#include <vector>

using namespace std;

vector<int> Q;

void printAry(vector<vector<int>>& target) {
    for(int i = 0; i < target.size(); ++i) {
        for(int j = 0; j < target[0].size(); ++j) {
            cout << target[i][j] << " ";
        }
        cout << endl;
        
    }
}

int main(void) {
    int n,i,j,place;
    cin >> n;

    vector<vector<int>> map;    
    vector<int> temp;
    for (i = 0; i < n+2; ++i) {
        for (j = 0; j < n+2; ++j) {
            if ((i==0) || (i==n+1) || (j==0) || (j==n+1)) {
                temp.push_back(0);
            }
            else {
                cin >> place;
                temp.push_back(place);
            }
        }
        map.push_back(temp);
        temp.clear();

        printAry(map);
    }
}