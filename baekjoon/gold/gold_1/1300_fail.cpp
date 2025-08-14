#include <iostream>
#include <vector>
using namespace std;

int N, K;

void init() {
    cin >> N >> K;
    K++;
}

int main() {
    init();

    int num = K/N + 1;
    int remainder = K%N;

    cout << num * remainder << endl;

    return 0;
}