#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N (13+1)
int N;                   // 배달지 개수
int arr[MAX_N][MAX_N];   // 길:비용
int visit[MAX_N];        // 방문처리
int select[MAX_N];       // 디버깅용
int call_cnt = 0;        // DFS 함수 호출 횟수
int ans = 0x7FFFFFFF;    // 최대값

static void inputData(void) {
    (void)scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            (void)scanf("%d", &arr[i][j]);
        }
    }
}

// 디버깅 용도
static void printArr(void) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 어떤 경로로 방문했는지 기록
static void printSelect(void) {
    for (int i = 1; i < N; ++i) {
        printf("%d ", select[i]);
    }
    printf("  ans : %d\n", ans);
}

// cnt : 방문한 개수, curr : 현재위치, cost : 현재까지의 비용
void DFS(int cnt, int curr, int cost) {
    
    if (cost >= ans) return;
    ++call_cnt;
    if (cnt == N) {
        int temp = arr[curr][1];
        if (temp == 0) return;
        if (cost + temp < ans) {
            ans = cost + temp; 
            printSelect();
        }
        return;
    }

    for (int i = 2; i <= N; i++) {
        if (visit[i] == 1 || arr[curr][i] == 0) continue;
        select[cnt] = i;
        visit[i] = 1;
        DFS(cnt + 1, i, cost + arr[curr][i]);
        visit[i] = 0;
    }
}

// 해밀턴 순환회로 - https://jungol.co.kr/problem/1681
void J1681_solution(void) {
    (void)freopen("J1681.txt", "r", stdin);
    inputData();
    //printArr();
    visit[1] = 1;
    DFS(1, 1, 0);
    printf("%d\n", ans);
    printf("call_cnt : %d\n", call_cnt);
}


#endif