#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> safe;
vector<vector<int>> map;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct cordi {
    int y;
    int x;
};
queue<cordi> que;

struct minmax {
    int min;
    int max;
};

void bfs(int size);
void input(int size) {
    int i,j;
    for(i = 0; i<size; ++i) {
        for(j = 0; j<size; ++j) {
            cin >> map[i][j];
        }
    }
}

void initialize(int size) {
    int i,j;
    for(i = 0; i<size; ++i) {
        for(j = 0; j<size; ++j) {
            safe[i][j] = false;
        }
    }
}

minmax find_minmax(int size) {
    int i,j;
    int min = 0xFFFFFFFF;
    int max = 0;
    for(i = 0; i<size; ++i) {
        for(j = 0; j<size; ++j) {
            if (map[i][j] < min) min = map[i][j];
            if (map[i][j] > max) max = map[i][j];
        }
    }
    return minmax{min, max};
}

minmax find_minmax(const vector<int> arr, int size) {
    int i = 0, max = 0;
    for(i = 0; i<arr.size(); ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return minmax{0, max};
}

int cnt_reigon(int w_height, int size) {
    int i,j;
    int cnt = 0;
    
    for(i = 0; i<size; ++i) {
        for(j = 0; j<size; ++j) {
            if(map[i][j] > w_height)  safe[i][j] = true;
            else safe[i][j] = false;
        }
    }

    for(i = 0; i<size; ++i) {
        for(j = 0; j<size; ++j) {
            if (safe[i][j] == true) {
                que.push(cordi{i,j});
                safe[i][j] = false;
                bfs(size);
                cnt += 1;
            }
        }
    }

    return cnt;
}

void bfs(int size) {

    while(!que.empty()) {
        cordi current = que.front();
        que.pop();
        int cx = current.x, cy = current.y;
        int nx, ny;

        for(int i = 0; i < 4; ++i) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if((nx < 0 || ny < 0 || nx >= size || ny >= size) || safe[ny][nx] == false) {
                continue;
            }
            safe[ny][nx] = false;
            que.push(cordi{ny,nx});

        }

    }

}



int main(void) {
    int size;
    vector<int> results;
    cin >> size;
    map.resize(size, vector<int>(size, 0));
    safe.resize(size, vector<bool>(size, false));


    input(size);
    minmax mm = find_minmax(size);
    for(int w_height = mm.min; w_height <= mm.max; ++w_height) {
        initialize(size);
        results.push_back(cnt_reigon(w_height, size));
    }

    minmax result = find_minmax(results, size);

    cout << result.max << endl;


}