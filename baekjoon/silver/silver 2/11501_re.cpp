#include <iostream>
#include <queue>
// #define size(a) (sizeof(a)/sizeof((a)[0]))
using namespace std;

long int cir(int*arr, int n) {
    int i,j;
    int max_price = 0;
    long int incom = 0;
    for(i = n-1; i >= 0; --i) {
        if (arr[i] > max_price)
            max_price = arr[i];
        else 
            incom += (max_price - arr[i]);
    }
    return incom;
}

int main(void) {
    int testcase,i,j,days,price;
    cin >> testcase;
    
    for (i = 0; i < testcase; ++i) {
        cin >> days;
        int arr[days] = {0,};
        
        for (j = 0; j < days; ++j) {
            cin >> price;
            arr[j] = price;
        }
        long int result = cir(arr,days);
        cout << result << endl;
        
    }
    
}