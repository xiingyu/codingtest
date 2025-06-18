#include <stdio.h>

#define MAX_N (20+1)
int target_arr[MAX_N];
int result = 0x7FFFFFFF;
int n, t;
int s1, s2;

int abs(int a) {
    return a > 0 ? a : -a;
}

void dfs(int th, int o1, int o2, int cost) {
    int cur_cost1, cur_cost2;
    if ((th >= t+1) && (cost < result)) {
        result = cost;
        //printf("result : %d\n", result);
        return;
    }
    else if (cost > result) {
        return;
    }
    // printf("%d %d\n", o1,o2);
    dfs(th + 1, target_arr[th], o2, abs(target_arr[th] - o1) + cost);
    dfs(th + 1, o1, target_arr[th], abs(target_arr[th] - o2) + cost);

}


void input_all(void) {
    scanf("%d %d %d %d", &n, &s1, &s2, &t);

    for (int i = 1; i <= t; ++i) {
        scanf("%d", target_arr + i);
    }
}


int main(void) {

    input_all();
    dfs(1, s1, s2, 0);
    printf("%d", result);


}