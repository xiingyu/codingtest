#include <iostream>
#include <queue>
using namespace std;
int N;
queue<int>cards;

int main() {
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cards.push(i);
    }

    while(!cards.empty()) {
        cout << cards.front() << " ";
        cards.pop();
        if(cards.size() == 1) {
            cout << cards.front() << " ";
            break;
        }
        cards.push(cards.front());
        cards.pop();
    }
    cout << endl;

    return 0;
}