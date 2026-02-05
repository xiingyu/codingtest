#include <iostream>
#include <vector>
using namespace std;

int N;

void printSpace(int depth) {
    for(int i = 0; i < depth; ++i) {
        cout << ' ';
    }

}

void printSET(int depth) {
    if(depth <= 2)  return;
    printSpace(depth);
    cout << '*';
    printSpace(depth--);
    cout << endl;
    
    printSpace(depth);
    cout << "* *";
    printSpace(depth--);
    cout << endl;
    
    printSpace(depth);
    cout << "*****";
    printSpace(depth--);
    cout << endl;

    printSET(depth);
}


int main() {
    cin >> N;
    printSET(N);

    return 0;
}