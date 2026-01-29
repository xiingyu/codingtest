#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> table;
vector<char> target;
int targetSize = 0;


void init() {
    string tempTable, tempTarget;
    cin >> tempTable >> tempTarget;
    for(char ch : tempTable) {
        table.push_back(ch);
    }
    for(char ch : tempTarget) {
        target.push_back(ch);
    }
    targetSize = (int)target.size();

}

void printTable() {
    for(char ch : table) {
        cout << ch << " " ;
    }
}

void suspect() {
    bool successFlag = true;
    int cnt = 0;


    while(successFlag) {
        successFlag = false;
        vector<char> temp;

        for(int i = 0; i < (int)table.size(); ++i) {
            if(table[i] == target[cnt]) {
                if(cnt == targetSize - 1) {
                    while(cnt--) {
                        temp.pop_back();
                    }
                    successFlag = true;
                    cnt = 0;
                } else {
                    cnt++;
                    temp.push_back(table[i]);
                }

            } 
            else if(cnt != targetSize){
                if(table[i] == target[0]) cnt = 1;
                else cnt = 0;

                temp.push_back(table[i]);
            }
            
        }
        
        table = temp;
        // printTable();
    }
}

void printAnswer() {
    for(char ch : table) {
        cout << ch;
    }
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    // printTable();
    suspect();
    if(table.empty()) cout << "FRULA";
    else printAnswer();


    return 0;
}
