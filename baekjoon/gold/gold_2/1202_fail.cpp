#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
vector<int> weights;
vector<int> bags;
vector<bool> usedBag;
// vector<int> results;
int resultSize = 0;
unsigned long long int result = 0;

struct dia {
    int w,v;
};
vector<dia> targets;

void init() {
    int w,v, bag;
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> w >> v;
        targets.push_back(dia{w,v});
    }

    for(int j = 0; j < K; ++j) {
        cin >> bag;
        bags.push_back(bag);
    }

    usedBag.resize(bags.size(), false);

    sort(bags.begin(), bags.end());
    sort(targets.begin(), targets.end(), [](const dia& a, const dia& b) {
        return a.v > b.v;
    });
}

void logic() {
    for(dia target : targets) {
        if(resultSize >= K) return;

        int weight = target.w;
        int bag = lower_bound(bags.begin(), bags.end(), weight) - bags.begin();

        // cout << "bag : " << bag  << " weight : " << weight << endl;
        while(bag < K) {
            // cout << "enter bag : " << bag << endl;
            if(usedBag[bag] == false) {
                usedBag[bag] = true;
                result += target.v;
                resultSize += 1;
                break;
            }
            else {
                bag++;
            }
        }
    }

}

void debug() {
    for(dia t : targets) {
        cout << t.w << " " << t.v << endl;;
    }

    for(int b : bags) {
        cout << b << endl;
    }
}

int main() {
    init();
    logic();
    // debug();

    cout << result;

    return 0;
}