#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int abs(int num) {
    if (num < 0) return num*(-1);
}


int main(void) {
    int i,j,n,m,temp;
    int step_cnt = 0, p_idx = 0, n_idx = 0;
    vector<int> positive,negative;

    ///preprocessing
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > 0) positive.push_back(temp);
        else negative.push_back(temp);
    }
    sort(positive.begin(), positive.end(),greater<>());
    sort(negative.begin(), negative.end());

    ///find last pang
    if (!(positive.empty() || negative.empty())) {
        if (positive[0] > abs(negative[0])) {
            step_cnt += positive[0];
            if (positive.size() <= m) positive.clear();
            p_idx += m;
        }
        else {
            step_cnt += abs(negative[0]);
            if (negative.size() <= m) negative.clear();
            n_idx += m;
        }
    }
    else if (positive.empty()) {
        step_cnt += abs(negative[0]);
        if (negative.size() <= m) negative.clear();
        n_idx += m;
    }
    else if (negative.empty()) {
        step_cnt += positive[0];
        if (positive.size() <= m) positive.clear();
        p_idx += m;
    }
    else {
        cout << -1 << endl;
        return -1;
    }

    // cout << step_cnt << endl;
    ///positive
    while(!positive.empty()) {
        if((positive.size() < m) || (positive.size()-p_idx - 1 < m)) {
            if (negative.size() == 0) step_cnt += (positive[p_idx])*2;
            else step_cnt += (positive[p_idx])*2;
            positive.clear();
            break;
        }
        step_cnt += (positive[p_idx])*2;
        p_idx += m;
    }


    ///negative
    while(!negative.empty()) {
        if((negative.size() < m) || (negative.size()-n_idx - 1 < m)) {
            step_cnt += abs((negative[n_idx]))*2;
            negative.clear();
            break;
        }
        step_cnt += abs((negative[n_idx]))*2;
        n_idx += m;
    }

    cout << step_cnt << endl;

    return 0;
}