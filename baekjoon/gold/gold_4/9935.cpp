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

vector<char> suspect() {
    int cnt = 0;
    vector<char> temp;
    bool popFlag = false;

    for(char ch : table) {
        popFlag = false;
        temp.push_back(ch);
        if((ch == target[targetSize - 1]) && ((int)temp.size() >= targetSize)) {
            popFlag = true;
            for(int i = 0; i < targetSize; ++i) {
                if(temp[temp.size() - i - 1] != target[targetSize - 1 - i]) {
                    popFlag = false;
                    break;
                }
            }
            if(popFlag){
                for(int i = 0; i < targetSize; ++i) {
                    temp.pop_back();
                }
            }

        }
        
    }
    return temp;
}


void printAnswer(vector<char> answer) {
    for(char ch : answer) {
        cout << ch;
    }
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    // printTable();
    vector<char> answer = suspect();
    if(answer.empty()) cout << "FRULA";
    else printAnswer(answer);


    return 0;
}
