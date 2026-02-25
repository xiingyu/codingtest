#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int N;


void printArrP(const vector<int>& arr) {
    cout << "size : " << arr.size() << " capacity : " << arr.capacity() << '\n';
}
void printArrC(const vector<int> arr) {
    cout << "size : " << arr.size() << " capacity : " << arr.capacity() << '\n';
}
void printArrCC(vector<int> arr) {
    cout << "size : " << arr.size() << " capacity : " << arr.capacity() << '\n';
}
void printArrCP(vector<int>& arr) {
    cout << "size : " << arr.size() << " capacity : " << arr.capacity() << '\n';
}

int main() {
    N = 100000000;
    auto start1 = chrono::high_resolution_clock::now();

    vector<int> arr1;
    for(int i = 0; i < N; ++i)
        arr1.push_back(1);
    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();
    printArrP(arr1);
    auto end2 = chrono::high_resolution_clock::now();

    auto start3 = chrono::high_resolution_clock::now();
    printArrC(arr1);
    auto end3 = chrono::high_resolution_clock::now();

    auto start4 = chrono::high_resolution_clock::now();
    printArrCC(arr1);
    auto end4 = chrono::high_resolution_clock::now();

    auto start5 = chrono::high_resolution_clock::now();
    printArrCP(arr1);
    auto end5 = chrono::high_resolution_clock::now();
    


    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
    auto duration4 = chrono::duration_cast<chrono::microseconds>(end4 - start4);
    auto duration5 = chrono::duration_cast<chrono::microseconds>(end5 - start5);
    // printArrP(arr1);
    cout << "push " << "duration1 : " << duration1.count() << " us" << endl;
    cout << "P    " << "duration2 : " << duration2.count() << " us" << endl;
    cout << "C    " << "duration3 : " << duration3.count() << " us" << endl;
    cout << "CC   " << "duration4 : " << duration4.count() << " us" << endl;
    cout << "CP   " << "duration5 : " << duration5.count() << " us" << endl;
    
    return 0;
}