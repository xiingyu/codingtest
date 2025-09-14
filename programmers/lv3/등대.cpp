#include <string>
#include <vector>

    #include <iostream>
using namespace std;

vector<int> degrees;
vector<int> lightedHouse;
vector<int> deletedDegs;
vector<bool> visited;
vector<vector<int>> table;

void init(const int& n, const vector<vector<int>>& lighthouse) {
    int i, a, b;
    
    table.resize(n+1);
    degrees.resize(n+1, 0);
    lightedHouse.resize(n+1, 0);
    deletedDegs.resize(n+1, 0);
    visited.resize(n+1, false);
    
    for(i = 0; i <lighthouse.size(); ++i) {
        a = lighthouse[i][0];   b = lighthouse[i][1];
        table[a].push_back(b);
        degrees[a] += 1;
        table[b].push_back(a);
        degrees[b] += 1;
    }
    
    for(i = 1; i <=n; ++i) {
        if(degrees[i] == 1) {
            deletedDegs[table[i][0]] += 1;
            lightedHouse[i] = 1;
        }
    } 
}

void dfs(int start, int countOff) {
    
    for(int next : table[start]) {
        if(!visited[next]) {
            visited[next] = true;
            
            if(deletedDegs[next] > 0 ) {
                lightedHouse[next] = 1;
                countOff = 0;
                
            } else if(lightedHouse[next] == 1) {
                countOff = 0;
                
            }else {
                countOff += 1;
                if(countOff == 2) {
                    lightedHouse[next] = 1;
                    countOff = 0;
                }
            }
        dfs(next, countOff);
        }
    }
}

int countHouse(const int& n) {
    int count = 0;
    for(int i = 1; i <= n; ++i) {
        if(lightedHouse[i] == 1) {
            count += 1;
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    return count;
}


int solution(int n, vector<vector<int>> lighthouse) {
    init(n,lighthouse);
    dfs(1,0);
    
    int answer = countHouse(n);
    
    // cout << answer;
    return answer;
}

int main() {
    int n,m;
    vector<vector<int>> lightedHouse;

    cin >> n >> m;
    while(m--) {
        int a,b;
        cin >> a >> b;
        lightedHouse.push_back({a,b});
    }

    solution(n, lightedHouse);

    return 0;
}