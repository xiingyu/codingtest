#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _HeapNode{
    ElementType data;
}HeapNode;

typedef struct _Heap {
    HeapNode* nodes;
    int capa;
    int used;
}Heap;


Heap* CreateHeap(int capa){
    Heap* temp = (Heap*)calloc(1, sizeof(Heap));
    if (temp == NULL) exit(1);
    temp->capa = capa;
    temp->used = 0;

    HeapNode* temp_HeadNode = (HeapNode*)calloc(capa, sizeof(HeapNode));
    if (temp_HeadNode == NULL) exit(1);
    temp->nodes = temp_HeadNode;

    return temp;

}

void Heap_Insert(Heap* minHeap, ElementType newdata ) {
    int curr = ++minHeap->used;
    if (curr > minHeap->capa) return ;
    
}


int main(void) {
    int capa, N;
    (void)scanf("%d, %d", &capa, &N);

    Heap* minHeap = CreateHeap(capa+1);

    // printf("%d %p", minHeap->capa, minHeap);


}