#include <stdio.h>

int N;
int target_y, target_x;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

int map[102][102];
int min[102][102];
int front = 0, rear = 0;

int defualt_cost = 0;

typedef struct _pixel {
    int y;
    int x;
    int cost;
} pixel;
pixel queue[102 * 102 * 102];


int enqueue(int fut_y, int fut_x, int fut_cost) {
    // if (rear >= 102*102*102) printf("core dump!!!!");
    queue[rear++] = (pixel){fut_y, fut_x, fut_cost};
}

pixel dequeue() {
    return queue[front++];
}

int sqr(int a) {
    return a*a;
}

void bfs() {

    while (front < rear) {
        pixel cur = dequeue();
        if ((cur.y == target_y) && (cur.x == target_x)) {
            if (min[cur.y][cur.x] > cur.cost) {
                min[cur.y][cur.x] = cur.cost;
            }
            continue;
        }
        // printf("%d %d %d\n", cur.y, cur.x, cur.cost);

        if (min[cur.y][cur.x] > cur.cost) {
            if (cur.y == 5 && cur.x == 1) {
                // printf("i've got a data (5,1) cost (%d)\n", cur.cost);
            }
            min[cur.y][cur.x] = cur.cost;
        }
        else {
            continue;
        }

        for(int i = 0; i < 4; ++i) {
            int fut_y = cur.y + dy[i];
            int fut_x = cur.x + dx[i];
            
            if (fut_y < 1 || fut_y > N || fut_x < 1 || fut_x > N)
                continue;

            int cur_val = map[cur.y][cur.x];
            int fut_val = map[fut_y][fut_x];
            int fut_cost;
            if (fut_val > cur_val) {
                fut_cost = cur.cost + sqr(fut_val - cur_val);
            }
            else {
                fut_cost = cur.cost + (cur_val - fut_val);
            }
            if (fut_cost > defualt_cost) continue;
            
            if (min[fut_y][fut_x] > fut_cost) {
                if (fut_y == 5 && fut_x == 1) {
                    // printf("arrived (5,1) with cur_cost=%d from (%d,%d)\n", cur.cost,cur.y, cur.x);
                    // printf("arrived (5,1) with fut_cost=%d from (%d,%d)\n\n", fut_cost,fut_y, fut_x);
                }

                // printf("%d %d %d\n", fut_y, fut_x, fut_cost);
                enqueue(fut_y, fut_x, fut_cost);
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

void printAry(int arr[102][102]) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void make_default_cost(void) {
    int i, temp;
    for(i = 1; i <= target_x; ++i) {
        if (map[target_y][i] > map[target_y][i-1]) {
            temp = sqr(map[target_y][i] - map[target_y][i-1]);
        }
        else {
            temp = map[target_y][i-1] - map[target_y][i];
        }
        defualt_cost += temp;
    }

}

void minmap_setting(void) {
    
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= N+1; j++) {
            min[i][j] = defualt_cost;
        }
    }
}



int main(void) {
    int i,j;
    inputData();
    
    make_default_cost();
    minmap_setting();
    
    for (i = 0; i <= N+1; ++i) {
        for (j = 0; j <= N+1; ++j) {
            if ((i==0)||(i==N+1)||(j==0)||(j==N+1)) {
                enqueue(j,i,0);
            }
        }
    }



    bfs();
    // printAry(min);
    printf("%d", min[target_y][target_x]);
    // printf("clear!!\n %d\n%d\n", front, rear);


}