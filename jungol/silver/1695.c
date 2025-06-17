#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sizeary(a) (sizeof(a)/sizeof((a)[0]))

int map [27][27] = {0};
int visited [27][27] = {0};
int danji[27*27/2 +1];
int danji_back = 0;

int que[27*27*2] = {0};
int front = 0;
int back =0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int apt_cnt = 0;

void findDanji(int n);
void scanMap(int n);
void printAry(int arr[27][27]);



void findDanji(int n) {
    while(front < back) {
        int i, future_y, future_x;
        int cur_y = que[front++], cur_x = que[front++];

        //상하좌우
        for(i = 0; i < 4; ++i) {
            future_y = cur_y + dy[i];
            future_x = cur_x + dx[i];
            if (visited[future_y][future_x] == 1) continue;

            if (map[future_y][future_x] == 1) {
                ++apt_cnt;
                que[back++] = future_y;
                que[back++] = future_x;
                visited[future_y][future_x] = 1;

            }
        }

    }
}



void scanMap(int n) {
    int y,x;

    for (y = 1; y <= n; ++y) {
        for(x = 1; x <= n; ++x) {
            if (visited[y][x] == 1) continue;
            
            visited[y][x] = 1;
            if (map[y][x] == 1) {
                que[back] = y;
                que[back+1] = x;
                back += 2; 
                findDanji(n);
                danji[danji_back++] = apt_cnt +1;
                apt_cnt = 0;
            }

        }
    }
}



void printAry(int arr[27][27]) {
    for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < 27; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int i,j,k,n, temp;
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            scanf("%1d", &temp);
            if (temp != 0) map [i][j] = 1;
        }
    }
    // printAry(map);
    // printf("print clear\n");
    scanMap(n);
    // printf("scan clear\n");
    // printAry(visited);

    // qsort(﻿①정렬할 값의 주소, ﻿②요소의 개수, ﻿③요소의 크기, ﻿④기준 함수);

    // //예시
    // qsort(N, 10, sizeof(int), compare);
    qsort(danji, danji_back, sizeof(int), compare);
    printf("%d\n", danji_back);
    for(int k = 0; k < sizeary(danji); ++k) {
        if (danji[k] != 0) printf("%d\n", danji[k]);
    }
    
}


// 윤석햄
#ifdef choi
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int visited[27][27] = { 0 };
int houseMap[27][27] = { 0 };
int direct[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int houseCount[25 * 25 / 2 + 1] = { 0 };
int countInd = 0;

enum Direction {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

enum Dimension {
    Y = 0,
    X
};

static void visitHouse(int x, int y) {
    visited[y][x] = 1;
    houseCount[countInd] += 1;
}

static void doRecursive(int x, int y) {
    if (!houseMap[y][x] || visited[y][x]) {
        return;
    }

    visitHouse(x, y);

    doRecursive(x + direct[UP][X], y + direct[UP][Y]);
    doRecursive(x + direct[DOWN][X], y + direct[DOWN][Y]);
    doRecursive(x + direct[LEFT][X], y + direct[LEFT][Y]);
    doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
}

static int updateHouseCount(int x, int y) {
    visitHouse(x, y);

    doRecursive(x + direct[DOWN][X], y + direct[DOWN][Y]);
    doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
}



static int compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

static void eraseStdinBuffer() {
    while (getchar() != '\n');
}

int main() {

    int N;
    (void)scanf("%d", &N);
    eraseStdinBuffer();


    int end = N + 1;
    for (int i = 1; i < end; i++) {
        int* pTmp = houseMap[i];
        for (int j = 1; j < end; j++) {
            pTmp[j] = getchar() - 48;
        }
        eraseStdinBuffer();
    }


    for (int y = 1; y <= end; y++) {
        for (int x = 1; x <= end; x++) {
            if (houseMap[y][x] && !visited[y][x]) {
                updateHouseCount(x, y);
                countInd++;
            }
        }
    }

    qsort(houseCount, countInd, sizeof(int), compare);

    printf("%d\n", countInd);
    for (int i = 0; i < countInd; i++) {
        printf("%d\n", houseCount[i]);
    }

    return 0;
}
#endif





#ifdef 개쩌는알고리즘
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** graph;
int* ans = NULL;
int n;

int dfs(int y, int x);
void memRelease();
int compare(const void* a, const void* b);

int main() {

    scanf("%d ",&n);
    
    graph = (int**)malloc((n+2)*sizeof(int*));
    if(graph == NULL){
        free(graph);
        exit(1);
    }

    for(int i=0;i<n+2;i++){
        graph[i] = (int*)malloc((n+2)*sizeof(int));
        
        if(*graph == NULL){
            for(int j=0;j<i;j++){
                free(graph[j]);
                exit(1);
            }
        }
        memset(graph[i],0,((n+2)*sizeof(int)));
    }

    for(int i=1;i<=n;i++){
        char line[26];
        scanf("%s",line);
        for(int j=1;j<=n;j++){
            graph[i][j] = line[j-1] - '0';
        }
    }
    

    int size = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j] == 1){
                ans = realloc(ans,(++size)*sizeof(int));
                if(ans == NULL){
                    memRelease();
                }
                ans[size-1] = dfs(i,j);
            }
        }
    }
    
    qsort(ans,size,sizeof(ans[0]),compare);
    
    printf("%d\n",size);
    for(int i=0;i<size;i++){
        printf("%d\n",ans[i]);
    }
    
    memRelease();
    free(ans);
    ans = NULL;
    
    return 0;
}

int dfs(int y, int x){

    int ans = 0;
    
    graph[y][x] = 0;
    ans++;
    
    int ny[4] = {1,-1,0,0};
    int nx[4] = {0,0,1,-1};

    int nexty;
    int nextx;
    for(int i=0;i<4;i++){

        nexty = ny[i]+y;
        nextx = nx[i]+x;

        if(graph[nexty][nextx]==1){
            ans += dfs(nexty,nextx);
        }
    }
    return ans;
}

void memRelease(){

    if(ans != NULL) {
        free(ans);
        ans = NULL;
    }

    if(graph == NULL) continue;
    
    for (int i = 0; i < n+2; i++) {
        free(graph[i]);
    }
    free(graph);
    graph = NULL;
}

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x<y) - (y-x);
}
#endif


#ifdef gang1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int visited[27][27] = { 0 };
int houseMap[27][27] = { 0 };
int direct[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int houseCount[25 * 25 / 2 + 1] = { 0 };
int countInd = 0;

enum Direction {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

enum Dimension {
    Y = 0,
    X
};

static void visitHouse(int x, int y) {
    visited[y][x] = 1;
    houseCount[countInd] += 1;
}

static void doRecursive(int x, int y) {
    if (!houseMap[y][x] || visited[y][x]) {
        return;
    }

    visitHouse(x, y);

    doRecursive(x + direct[UP][X], y + direct[UP][Y]);
    doRecursive(x + direct[DOWN][X], y + direct[DOWN][Y]);
    doRecursive(x + direct[LEFT][X], y + direct[LEFT][Y]);
    doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
}

static int updateHouseCount(int x, int y) {
    visitHouse(x, y);

    doRecursive(x + direct[DOWN][X], y + direct[DOWN][Y]);
    doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
}



static int compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

static void eraseStdinBuffer() {
    while (getchar() != '\n');
}

int main() {

    int N;
    (void)scanf("%d", &N);
    eraseStdinBuffer();

    int end = N + 1;
    for (int i = 1; i < end; i++) {
        int* pTmp = houseMap[i];
        for (int j = 1; j < end; j++) {
            pTmp[j] = getchar() - 48;
        }
        eraseStdinBuffer();
    }


    for (int y = 1; y <= end; y++) {
        for (int x = 1; x <= end; x++) {
            if (houseMap[y][x] && !visited[y][x]) {
                updateHouseCount(x, y);
                countInd++;
            }
        }
    }

    qsort(houseCount, countInd, sizeof(int), compare);

    printf("%d\n", countInd);
    for (int i = 0; i < countInd; i++) {
        printf("%d\n", houseCount[i]);
    }

    return 0;
}

#endif



#if 0 //강사님 최종
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX_N (25 + 2)
int N;
int houseMap[MAX_N][MAX_N] = { 0 };
int direct[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int houseCount[(25 * 25) / 2 + 1] = { 0 };
int countInd = 0;

enum Direction {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

enum Dimension {
    Y = 0,
    X
};

static int compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    if (*(int*)first < *(int*)second)
        return -1;
    return 0;
}

void inputData(void) {
    char temp[MAX_N] = { 0 };
    (void)scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        (void)scanf("%s", temp+1);
        int* pTmp = houseMap[i];
        for (int j = 1; j <= N; j++) {
            pTmp[j] = temp[j] - 48;
        }
    }
}

void printHouseMap(void) {
    printf("countInd = %d\n", countInd);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%d ", houseMap[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 
}

static void visitHouse(int x, int y) {
    houseMap[y][x] = countInd + 2;
    houseCount[countInd] += 1;
}

static void doRecursive(int x, int y) {
    if (houseMap[y][x] != 1) {
        return;
    }
    visitHouse(x, y);
    doRecursive(x + direct[UP][X], y + direct[UP][Y]);
    doRecursive(x + direct[DOWN][X], y + direct[DOWN][Y]);
    doRecursive(x + direct[LEFT][X], y + direct[LEFT][Y]);
    doRecursive(x + direct[RIGHT][X], y + direct[RIGHT][Y]);
}

static void makeHouseCount(void) {
    countInd = 0;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (houseMap[y][x] == 1) {
                doRecursive(x, y);
                //printHouseMap();  // 디버깅
                countInd++;
            }
        }
    }
}

void outputData(void) {
    qsort(houseCount, countInd, sizeof(int), compare);

    printf("%d\n", countInd);
    for (int i = 0; i < countInd; i++) {
        printf("%d\n", houseCount[i]);
    }
}

void danji_01(void) {

    inputData();
    //printHouseMap(); // 디버깅
    makeHouseCount();
    outputData();    
}



#endif


//개쩌는 코드의 강사님버전
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** graph;
int* ans = NULL;
int n;

int dfs(int y, int x);
void memRelease();
int compare(const void* a, const void* b);

int main() {

    scanf("%d ", &n);

    graph = (int**)malloc((n + 2) * sizeof(int*));
    if (graph == NULL) {
        free(graph);
        exit(1);
    }

    for (int i = 0; i < n + 2; i++) {
        graph[i] = (int*)malloc((n + 2) * sizeof(int));

        if (*graph == NULL) {
            for (int j = 0; j < i; j++) {
                free(graph[j]);
                exit(1);
            }
        }
        memset(graph[i], 0, ((n + 2) * sizeof(int)));
    }

    for (int i = 1; i <= n; i++) {
        char line[26];
        scanf("%s", line);
        for (int j = 1; j <= n; j++) {
            graph[i][j] = line[j - 1] - '0';
        }
    }


    int size = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1) {
                ans = realloc(ans, (++size) * sizeof(int));
                if (ans == NULL) {
                    memRelease();
                }
                ans[size - 1] = dfs(i, j);
            }
        }
    }

    qsort(ans, size, sizeof(ans[0]), compare);

    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", ans[i]);
    }

    memRelease();
    free(ans);
    ans = NULL;

    return 0;
}

int dfs(int y, int x) {

    int ans = 1;

    graph[y][x] = 0;

    int ny[4] = { 1,-1,0,0 };
    int nx[4] = { 0,0,1,-1 };

    int nexty;
    int nextx;
    for (int i = 0; i < 4; i++) {

        nexty = ny[i] + y;
        nextx = nx[i] + x;

        if (graph[nexty][nextx] == 1) {
            ans += dfs(nexty, nextx);
        }
    }
    return ans;
}

void memRelease() {

    if (ans != NULL) {
        free(ans);
        ans = NULL;
    }

    if (graph == NULL) continue;

    for (int i = 0; i < n + 2; i++) {
        free(graph[i]);
    }
    free(graph);
    graph = NULL;
}

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return (x < y) - (y - x);
}
#endif