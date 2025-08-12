#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 0x7FFFFFFF
using namespace std;

int minH, maxH;
int N, M;
vector<int> trees;

void init() {
    int i, temp;
    cin >> N >> M;
    for(i = 0; i < N; ++i) {
        cin >> temp;
        trees.push_back(temp);
    }

    minH = *min_element(trees.begin(), trees.end());
    maxH = *max_element(trees.begin(), trees.end());
}

int cutting(int height) {
    long int count = 0;
    for(int tree : trees) {
        if(tree > height)   count += (tree - height);
        if(count > MAX) return MAX;
    }
    return count;
}

//딱 m이 필요한게 아니기 때문에, result를 저장해두므로써 그 전 결정을 기록할 수 있도록.
int binarySearch() {
    int s,e,mid, cutted;
    int result;
    s = 0;   e = maxH;
    while(s < e) {
        mid = (s + e) / 2;
        cutted = cutting(mid);
        // cout << mid << " " << cutted << endl;

        if(cutted < M) {
            e = mid;
        }
        else if (cutted > M) {
            result = mid;
            s = mid + 1;
        }
        else {
            return mid;
        }
    }
    return result;
}

int main() {
    init();
    if (N == 1) {
        cout << trees[0] - M << endl;
    }
    else {
        int result = binarySearch();
        cout << result << endl;
    }

    return 0;
}