#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int result = 0;
vector<int> bags;
struct jew {
    int w,v;
};
vector<jew> targets;
vector<bool> usedTargets;

void init() {
    int w,v, b;
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> w >> v;
        targets.push_back(jew{w,v});
    }

    for(int i = 0; i < K; ++i) {
        cin >> b;
        bags.push_back(b);
    }

    usedTargets.resize(N, false);

    sort(bags.begin(), bags.end());
    sort(targets.begin(), targets.end(), [](const jew& a, const jew&b) {
        if(a.w == b.w) {
            return a.v > b.v;
        }
        return a.w < b.w;
    });
}

void logic() {
    int depth = 0;

    int maxIdx = -1;
    int maxVal = 0;

    int lastestIdx = 0;
    int secondMaxValue = 0;
    int secondMaxIdx = 0;

    for(int bag : bags) {
        if(depth >= N) break;

        // cout << "bag : " << bag << endl;
        for(int i = lastestIdx; i < N; ++i) {
            // cout << "i : " << i << " targets[i].v : " << targets[i].v << endl;
            if(targets[i].w <= bag) {
                if(usedTargets[i] == false) {
                    int val = targets[i].v;
                    if(maxVal < val) {
                        // cout << "when i : " << i << " w : " << targets[i].w << "  v : " << targets[i].v << endl;
                        if(secondMaxValue < val) {
                            secondMaxIdx = maxIdx;
                            secondMaxValue = maxVal;
                        }

                        maxVal = val;
                        maxIdx = i;
                    }
                }
            }
            else {
                lastestIdx = i;
                break;
            }
        }

        if(secondMaxValue > maxVal) {
            // cout << "second! " << secondMaxValue << endl;
            result += secondMaxValue;
            secondMaxValue = maxVal;
            usedTargets[secondMaxIdx] = true;
            maxIdx = secondMaxIdx;
            depth += 1;
        }
        else {
            // cout << "first! " << maxVal << endl;
            result += maxVal;
            maxVal = 0;
            if(maxIdx != -1)   {
                depth += 1; 
                usedTargets[maxIdx] = true;
            }
            maxIdx = -1;
            
        }
    }
}

void debug() {
    cout << "targetSize  " << targets.size() << endl;
    for(int i : usedTargets) {
        if (i == false) {
            cout << 0 << " ";
        }
        else {
            cout << "1 ";
        }
    }
}

int main() {
    init();
    logic();
    // debug();
    // cout << endl;

    cout << result << endl;

    return 0;
}