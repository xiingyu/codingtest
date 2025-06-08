#include <iostream>
#include <queue>
#define size(a) (sizeof(a)/sizeof((a)[0]))
using namespace std;

/*
void slice(int* src, int start, int end, int* dest) {
    for (int i = start; i < end; ++i) {
        dest[i - start] = src[i];
    }
}
*/



int max_value_ind(queue<int> que){
    int temp = 0, max_val = 0;
    while (!que.empty()) {
        temp = que.front();
        que.pop();
        if (temp > max_val)  max_val = temp;
    }
    return  max_val;
}

int cir(int* arr, int n) {
    queue<int> days;
    queue<int> purchase;
    int i = 0, now = 0, income = 0;
    int max_price, now_price;
    
    
    for (i = 0; i < n; ++i) {
        days.push(arr[i]);
    }
    
    max_price = max_value_ind(days);
    while(!days.empty()) {
        now_price = days.front();
        days.pop();
        
        if (max_price == now_price) {
            while(!purchase.empty()) {
                income += now_price - purchase.front();
                purchase.pop();
            }
            max_price = max_value_ind(days);
        }
        else if (now_price < max_price) {
            purchase.push(now_price);
        }
        else {
            continue;
        }
    }
    
    return income;
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
        int result = cir(arr,days);
        cout << result << endl;
        
    }
    
}