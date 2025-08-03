#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M,N;
int minLength, maxLength;
vector<int> ggaggas;

void init() {
    int i, temp;
    cin >> M >> N;
    for(i = 0; i < N; ++i) {
        cin >> temp;
        ggaggas.push_back(temp);
    }
    sort(ggaggas.begin(), ggaggas.end(), [](const int& a, const int& b){
        return a < b;
    });
    minLength = ggaggas[0];
    maxLength = *max_element(ggaggas.begin(), ggaggas.end());
}

bool isItOkay(int targetLength) {
    int i;
    int count = 0;
    for(i = 0; i < N; ++i) {
        count += ggaggas[i] / targetLength;
    }
    if(count >= M) return true;
    else return false;
}

int binarySearch(int st, int ed) {
    int mid;
    int lastCheck = 0;

    while(st < ed) {
        // cout << st << " " << ed << endl;
        mid = (st + ed) / 2;


        if(isItOkay(mid)) {
            st = mid+1;
        }
        else{
            ed = mid;
        }
    }

    return st - 1;

}

int main() {
    init();
    int result = binarySearch(1, maxLength+1);

    cout << result << endl;

    return 0;
}