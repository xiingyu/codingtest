#include <stdio.h>

int N;
int target_y, target_x;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

int map[102][102];
int min[103][103] = {0};
int front = 0, rear = 0;

typedef struct _pixel {
    int x;
    int y;
    int cost;
} pixel;
pixel queue[100 * 100];


int enqueue(int fut_y, int fut_x, int fut_cost) {
    queue[rear++] = (pixel){fut_y, fut_x, fut_cost};
}

pixel dequeue() {
    return queue[front++];
}

int sqr(int a) {
    return a*a;
}

void bfs() {

    while (front <= rear) {
        pixel cur = dequeue();
        if ((cur.y == target_y) && (cur.x == target_x)) {
            if (min[cur.y][cur.x] > cur.cost) {
                min[cur.y][cur.x] = cur.cost;
            }
            continue;
        }

        if ((min[cur.y][cur.x] > cur.cost) && (min[cur.y][cur.x] != 0)) {
            min[cur.y][cur.x] = cur.cost;
        }
        else {
            continue;
        }

        for(int i = 0; i < 4; ++i) {
            int fut_y = cur.y + dy[i];
            int fut_x = cur.x + dx[i];

            int cur_val = map[cur.y][cur.x];
            int fut_val = map[fut_y][fut_x];
            if (fut_val > cur_val) {
                enqueue(fut_y, fut_x, cur.cost + sqr(fut_val - cur_val));
            }
            else {
                enqueue(fut_y, fut_x, cur.cost + (cur_val - fut_val));
            }
        }
    }
}



void inputData(void) {

    (void)scanf("%d %d %d", &N, &target_y, &target_x);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            (void)scanf("%d", &map[i][j]);
        }
    }
}

void printAry(int arr[103][103]) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int i,j;
    inputData();
    
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            if ((i==1)||(i==N)||(j==1)||(j==N)) {
                enqueue(j,i,0);
            }
        }
    }
    bfs();
    printAry(min);
    printf("%d", min[target_y][target_x]);

}