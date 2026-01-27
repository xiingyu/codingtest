#include <iostream>
#include <deque>
#include <string>
using namespace std;

int T, n;
deque<int> table;

bool isItNum(char target) {
    int targetInt = (int)target - '0';
    if(targetInt >= 0 && targetInt <= 9) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    bool reverseFlag = false;
    bool failFlag = false;

    cin >> T;

    while(T--) {
        reverseFlag = failFlag = false;
        table.clear();
        string cmd;
        string nums;
        string temp;

        cin >> cmd >> n >> nums;

        for(int i = 0; i < (int)nums.size() ; ++i) {
            if(isItNum(nums[i])) {
                temp.push_back(nums[i]);
            } else {
                if(!temp.empty()) {
                    // cout << temp << endl;
                    table.push_back(stoi(temp));
                    // cout<< "push!!!" << endl;
                }
                temp.clear();
            }
        }

        for(char command : cmd) {
            if(command == 'R') {
                reverseFlag = !reverseFlag;
            } else {

                if(table.empty())   {
                    failFlag = true;
                    break;
                }

                if(reverseFlag) {
                    table.pop_back();
                } else {
                    table.pop_front();
                }
            }
        }

        if(failFlag) {
            cout <<"error\n"; 
        }

        else {
            cout << '[';
            while(!table.empty()) {
                if(reverseFlag) {
                    cout << table.back();
                    table.pop_back();
                }
                else {
                    cout << table.front();
                    table.pop_front();
                }

                if(!table.empty()) cout << ',';
            }
            cout << "]\n";

        }



    }


    return 0;
}


/*
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int n;
string chs;
deque<int> table;

bool isItNum(char target) {
    if((int)target - '0' <= 9 && (int)target - '0' >= 1) return true;
    else return false;

}

int main() {
    cin >> n;
    cin >> chs;
    string temp;

    for(int i = 0; i < chs.size(); ++i) {
        if(isItNum(chs[i])) {
            temp.push_back(chs[i]);
        } else {
            if(!temp.empty()) {
                table.push_back(stoi(temp));
                
            }
            temp.clear();
        }
        

        
    }

    while(!table.empty()) {
        cout << table.front() <<endl;
        table.pop_front();
    }

    return 0;
}
    */