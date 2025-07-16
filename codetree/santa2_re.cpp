#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int beltNum;
vector<deque<int>> belts;

void initial() {
    int n,i, temp;
    cin >> beltNum >> n;
    belts.resize(beltNum+1);
    for(i = 1; i <= n; ++i) {
        cin >> temp;
        belts[temp].push_back(i);
    }
}

int moveAll(int src, int dst) {
    if(!belts[src].empty()) {
        belts[dst].insert(belts[dst].begin(), belts[src].begin(), belts[src].end());
        belts[src].clear();
    }

    /*
    
    belts[dst].insert(belts[dst].begin(), belts[src].begin(), belts[src].begin() + floor);
    for(int i = 0; i < floor; ++i) {
        // belts[dst].push_front(belts[src].front());   
        belts[src].pop_front();
    }
        */
    return belts[dst].size();

}

int moveOnce(int src, int dst) {
    if(belts[src].empty() && belts[dst].empty()) return 0;
    else if (belts[src].empty() && !belts[dst].empty()) {
        belts[src].push_front(belts[dst].front());
        belts[dst].pop_front();
    }
    else if (belts[dst].empty() && !belts[src].empty()) {
        belts[dst].push_front(belts[src].front());
        belts[src].pop_front();
    }
    else {
        int temp;
        temp = belts[src].front();  
        belts[src][0] = belts[dst][0];
        belts[dst][0] = temp;
    }
    return belts[dst].size();
}

int divide(int src, int dst) {
    int floor;
    if(belts[src].empty() && belts[dst].empty()) return 0;
    floor = (int)(belts[src].size()/2);
    if(floor == 0) return 0;

    belts[dst].insert(belts[dst].begin(), belts[src].begin(), belts[src].begin() + floor);
    belts[src].erase(belts[src].begin(), belts[src].begin() + floor);

    return belts[dst].size();
}

int getInfoProduct(int id) {
    int targetBelt, targetIndex = -1;
    int maxIndex = -1;
    int a, b, i, j;

    for(i = 0; i < belts.size(); ++i) {
        for(j = 0; j < belts[i].size(); ++j) {
            if(belts[i][j] == id) {
                targetBelt = i;
                targetIndex = j;
            }
        }
    }
    
    maxIndex = belts[targetBelt].size()-1;
    if(maxIndex == 0) {
        a = -1;
        b = -1;
    }
    else if(targetIndex == maxIndex) {
        a = belts[targetBelt][targetIndex - 1];
        b = -1;
    }
    else if (targetIndex == 0) {
        a = -1;
        b = belts[targetBelt][targetIndex + 1];
    }
    else {
        a = belts[targetBelt][targetIndex - 1];
        b = belts[targetBelt][targetIndex + 1];
    }
    
    // cout << a << " " << b << endl;
    return a + (2 * b);
}

int getInfoBelt(int belt) {
    int a,b,c = -1;

    if(belts[belt].empty()) {
        a = -1; b = -1; c = 0;
    } else {
        a = belts[belt].front();
        b = belts[belt].back();
        c = belts[belt].size();
    }
    return a + (b * 2) + (c * 3);
}

void printMap(){
    int i,j;
    for(i = 0; i < belts.size(); ++i) {
        for(j = 0; j < belts[i].size(); ++j) {
            cout << belts[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int n, i, temp, src, dst, rst;
    cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> temp;
        switch (temp) {
            case 100 :
                initial();
                break;
            case 200 :
                cin >> src >> dst;
                rst = moveAll(src, dst);
                cout << rst << endl;
                break;
                
            case 300 :
                cin >> src >> dst;
                rst = moveOnce(src, dst);
                cout << rst << endl;
                break;
                
            case 400 :
                cin >> src >> dst;
                rst = divide(src, dst);
                cout << rst << endl;
                break;
                
            case 500 :
            // cout << "start 5 :: " << endl;
            //     printMap();
                cin >> src;
                rst = getInfoProduct(src);
            // cout << "end 5 :: " << endl;
            //     printMap();
                cout << rst << endl;
                break;
                
            case 600 :
                cin >> src;
                rst = getInfoBelt(src);
                cout << rst << endl;
                break;
        }
    }
    // printMap();

}