#include <iostream>
#include <vector>
using namespace std;

int t,n;
struct point{
    int y,x;
};
point home, goal;
vector<bool> visited;

int culManhattanDist(const point& a, const point&b) {
    return abs(a.y - b.y) + abs(a.x - b.x);
}

bool dfs(const vector<point>& stores, int curr) {
    bool answer = false;
    if(curr == n+1) {
        return true;
    }

    for(int i = 0; i < n+2; ++i) {
        if(i == curr) continue;
        point next = stores[i];

        if(visited[i] == false && culManhattanDist(next, stores[curr]) <= 1000) {
            visited[i] = true;
            answer = dfs(stores, i);
            if(answer)  return answer;
            // visited[i] = false;
        }
        

    }

    return answer;
}

int main() {
    point temp;
    cin >> t;
    
    while(t--) {
        cin >> n;
        vector<point> stores;
        visited.assign(n+2, false);

        cin >> home.x >> home.y;
        stores.push_back(home);

        for(int i = 0; i < n; ++i) {
            cin >> temp.x >> temp.y;
            stores.push_back(temp);
        }
        cin >> goal.x >> goal.y;
        stores.push_back(goal);

        visited[0] = true;

        if(dfs(stores,0))   cout << "happy\n";
        else        cout << "sad\n";
    }


    return 0;
}