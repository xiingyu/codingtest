#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int N;


void printArr(const vector<int>& arr) {
    cout << "size : " << arr.size() << " capacity : " << arr.capacity() << endl;
}

int main() {
    N = 10000000;
    auto start1 = chrono::high_resolution_clock::now();

    vector<int> arr1;
    for(int i = 0; i < N; ++i)
        arr1.push_back(1);
    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();
    vector<int> arr2(N);
    for(int i = 0; i < N; ++i)
        arr2[i] = 1;
    auto end2 = chrono::high_resolution_clock::now();
    
    auto start3 = chrono::high_resolution_clock::now();
    vector<int> arr3;
    arr3.reserve(N);
    for(int i = 0; i < N; ++i)
        arr3.push_back(1);
    auto end3 = chrono::high_resolution_clock::now();


    auto start4 = chrono::high_resolution_clock::now();
    vector<int> arr4;
    arr4.resize(N);
    for(int i = 0; i < N; ++i)
        arr4[i] = 1;
    auto end4 = chrono::high_resolution_clock::now();
    
    
    auto start5 = chrono::high_resolution_clock::now();
    vector<int> arr5;
    arr5.resize(N-1);
    for(int i = 0; i < N; ++i) {
        if(i < N-1)
            arr5[i] = 1;
        else 
            arr5.push_back(1);
    }
    auto end5 = chrono::high_resolution_clock::now();

    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
    auto duration4 = chrono::duration_cast<chrono::microseconds>(end4 - start4);
    auto duration5 = chrono::duration_cast<chrono::microseconds>(end5 - start5);
    printArr(arr1);
    printArr(arr2);
    printArr(arr3);
    printArr(arr4);
    printArr(arr5);
    cout << "push_back " << "duration1 : " << duration1.count() << " us" << endl;
    cout << "[i] = 1   " << "duration2 : " << duration2.count() << " us" << endl;
    cout << "reserve   " << "duration3 : " << duration3.count() << " us" << endl;
    cout << "resize    " << "duration4 : " << duration4.count() << " us" << endl;
    cout << "resize    " << "duration5 : " << duration5.count() << " us" << endl;
    arr1.clear();arr2.clear();arr3.clear();arr4.clear();
    vector<int>().swap(arr5);
    printArr(arr1);
    printArr(arr2);
    printArr(arr3);
    printArr(arr4);
    printArr(arr5);
    
    return 0;
}