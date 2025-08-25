#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;


auto cmpLower = [](const int& a, const int& b) {
    return a > b;
};

auto cmpUpper = [](const int& a, const int& b) {
    return a < b;
};
priority_queue<int, vector<int>, decltype(cmpLower)> FLowPQ(cmpLower);
priority_queue<int, vector<int>, decltype(cmpUpper)> FHighPQ(cmpUpper);

bool cmpLowInt(const int&a, const int& b)    {
    return a > b ? false : true;
}

int absol(const int& a) {
    return (a < 0) ? -a : a;
}

void logic() {
    int i, temp;
    for(i = 3; i <= N; ++i) {
        int addedSide = 0;  //1 is FHIGH    2 is FLOW
        cin >> temp;

        int HTOP = FHighPQ.top();   int LTOP = FLowPQ.top();
        if(temp < LTOP) {
            FHighPQ.push(temp);
            addedSide = 1;
            // cout << "pushed : " << temp << endl;
        } else {
            FLowPQ.push(temp);
            addedSide = 2;
        }
        
        if(absol(FHighPQ.size() - FLowPQ.size()) >= 2) {
            // cout << " joined" << endl;
            if(FHighPQ.size() > FLowPQ.size()) {
                FLowPQ.push(FHighPQ.top()); FHighPQ.pop();
                // cout << "size : " << FHighPQ.size() << " " << FLowPQ.size() << endl;
            } else {
                FHighPQ.push(FLowPQ.top()); FLowPQ.pop();
            }
        }

        if(i % 2 == 0) {
            cout << min(FLowPQ.top(), FHighPQ.top()) << "\n";
        } else {
            if(addedSide == 1) {
                cout << FHighPQ.top() << "\n";
            } else {
                cout << FLowPQ.top() << "\n";
            }
        }
        

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int temp, first;
    
    cin >> N;
    cin >> first;

    if (N==1) {
        cout << first << "\n";
    } else if(N >= 2) {
        cin >> temp;
        cout << first << "\n";
        if(cmpLowInt(first, temp)) {
            // cout << "FL : " << temp << " FH : " << first << endl;
            FLowPQ.push(temp);
            FHighPQ.push(first);
        } else {
            FLowPQ.push(first);
            FHighPQ.push(temp);
        }
        cout << min(FLowPQ.top(), FHighPQ.top()) << "\n";
    }

    if(N >= 2) {

        logic();
    }


    return 0;
}
