// 등산로 찾기 - https://jungol.co.kr/problem/1111
#if 1
#define DEBUGGING 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N 102
#define MAX_SIZE 100000
#define MAX_COST 0x7fffffff

typedef struct node {
    int r;
    int c;
}Node;

Node queue[MAX_SIZE] = { 0, };
int front = 0, rear = 0;
// for 문을 돌면서 rear의 값을 출력해 볼 것
//rear = (rear + 1) % 5;
void enqueue(Node node) {
    queue[rear++] = node;    
}

Node dequeue() {
    return queue[front++];
}

int N;
int peakR, peakC;
int map[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void initCost() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            cost[i][j] = MAX_COST;
        }
    }
}

void inputData() {
    (void)scanf("%d", &N);
    (void)scanf("%d %d", &peakR, &peakC);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            (void)scanf("%d", &map[i][j]);
        }
    }
}

void printArray(int (*arr)[MAX_N]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == MAX_COST)
                printf("INF ");
            else
                printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int BFS(void) {
    Node curr = { 0 };
    int temp = 0;
    int new_cost = 0;
    
    // 테두리 다 enqueue
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1 || i == N || j == 1 || j == N) {
                cost[i][j] = map[i][j] * map[i][j];
                enqueue((Node) { i, j });
            }
        }
    }
    //printArray(cost);
    while (front != rear) {
        curr = dequeue();
        for (int i = 0; i < 4; i++) {
            int n_r = curr.r + dr[i];
            int n_c = curr.c + dc[i];

            if (map[n_r][n_c] == 0) continue;  
            temp = map[curr.r][curr.c] - map[n_r][n_c];
            if (temp < 0) temp *= temp;
            new_cost = cost[curr.r][curr.c] + temp;

            if (new_cost < cost[n_r][n_c]) {
                cost[n_r][n_c] = new_cost;
                enqueue((Node){n_r, n_c});
            }
        }
    }
    return cost[peakR][peakC];
}

int main() {  
#if DEBUGGING
    (void)freopen("J1111.txt", "rt", stdin);
#endif
    inputData();
    initCost();
#if DEBUGGING
    //printArray(map);
    //printArray(cost); 
#endif 
    printf("%d\n", BFS());
    printArray(cost);
    return 0;
}
#endif