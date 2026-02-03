#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N,M;
vector<int> templete;
vector<int> table;


void init() {
    int temp;
    cin >> N;


    for(int i = 0; i < N; ++i) {
        cin >> temp;
        templete.push_back(temp);        
    }
    
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        if(templete[i] == 0) {
            table.push_back(temp);  
        }      
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int temp;
    init();
    cin >> M;

    deque<int> dq;

    for(int target : table) {
        dq.push_back(target);
    }

    while(M--) {
        cin >> temp;
        dq.push_front(temp);
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0;
}