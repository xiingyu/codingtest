#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> table;
vector<vector<int>> result;

int n,m;


void dfs(int start, int depth, vector<int> current) {
    if(depth >= m) {
        result.push_back(current);
        return ;
    }
    int i;
    for(i = start; i < n; ++i ) {
        current.push_back(table[i]);
        dfs(i+1, depth + 1, current);
        current.pop_back();
    }
}

bool issame(vector<int> target, vector<int> backward_arr) {
    for(int i = 0; i < target.size(); ++i) {
        if(target[i] != backward_arr[i]) {
            return false;
        }
    }
    return true;

}

void print_map() {
    int i,j,k;
    bool pass_flag;
    for(i = 1; i < result.size(); ++i) {
        pass_flag = false;
        if(i < result.size()) {
            for(k = i+1; k < result.size(); ++k) {
                // cout << "K : " << k << " i : " << i << endl;;
                if(k == 0) continue;
                if(issame(result[i], result[k])) {
                    pass_flag = true;
                    continue;
                }
            }

        }
        if (!pass_flag) {
            for(j = 0; j < m; ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        
    }
}


int main(void) {
    int temp, i;
    cin >> n >> m;
    result.resize(1, vector<int>(m,0));
    for(i = 0; i < n; ++i) {
        cin >> temp;
        table.push_back(temp);
    }
    sort(table.begin(),table.end());
    vector<int> tmp;
    dfs(0,0,tmp);
    print_map();

}
