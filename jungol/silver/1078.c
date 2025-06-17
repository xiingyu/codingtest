#define MAX_N (100+2)

typedef struct _node {
    int r;
    int c;
}node;

int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];

node Queue[MAX_N * MAX_N];
int front, rear;

//expression1
// void enqueue(int r, int c, int value) {
//     Queue[rear].r = r;
//     Queue[rear].c = c;
//     Queue[rear].value = value;
//     ++rear;
// }


//expression2
void enqueue(int r, int c) {
    Queue[rear++] = (node){ r, c};
}

node dequeue(void) {
    return Queue[front++];
}



int BFS(int sy, int sx) {
    front = rear = 0;
    enqueue(sy,sx);
    map[sy][sx] = 3;

    return 0;
}