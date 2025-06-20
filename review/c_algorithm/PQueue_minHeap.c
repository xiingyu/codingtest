#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _HeapNode {
    ElementType Data;

}HeapNode;

typedef struct _Heap {
    HeapNode* nodes;
    int capacity;
    int used_size;
}Heap;

Heap* HEAP_Create(int capacity) {
    Heap* new_heap = NULL;
    new_heap = (Heap*)calloc(1, sizeof(Heap));
    if (new_heap == NULL) {
        exit(1);
    }
    new_heap->capacity = capacity;
    new_heap->nodes = (HeapNode*)calloc(capacity, sizeof(HeapNode));
    if (new_heap->nodes == NULL) {
        free(new_heap);
        exit(1);
    }
    new_heap->used_size = 0;
    return new_heap;
}

void HEAP_Destroy(Heap* h) {
    free(h->nodes);
    free(h);
}
void swap(HeapNode* a, HeapNode* b) {
    ElementType temp;
    temp = a->Data;
    a->Data = b->Data;
    b->Data = temp;
}

void HEAP_PrintNodes(Heap* minHeap) {
    for (int i = 1; i <= minHeap->used_size; i *= 2) {
        for (int j = i; j < i * 2; j++) {
            printf("%d ", minHeap->nodes[j].Data);
        }
        printf("\n");
    }
}
void HEAP_Insert(Heap* heap, ElementType newData) {
    int curr = ++heap->used_size;
    HeapNode* nodes = heap->nodes;

    heap->nodes[curr].Data = newData;
    int parent = curr / 2;
    while ((parent > 0) && (nodes[parent].Data > nodes[curr].Data)) {
        swap(nodes + parent, nodes + curr);
        curr = parent;
        parent /= 2;
    }
}

void HEAP_Insert_For(Heap* heap, ElementType newData) {
    int curr = ++heap->used_size;
    HeapNode* nodes = heap->nodes;

    heap->nodes[curr].Data = newData;
    for (int parent = curr / 2; parent > 0; curr = parent, parent /= 2) {
        if (nodes[parent].Data <= nodes[curr].Data) break;
        swap(nodes + parent, nodes + curr);
    }
}

// 데이터가 없을때는 -1 반환 (Underflow)
//ElementType HEAP_Delete(Heap* heap) {
//    HeapNode* nodes = heap->nodes;
//
//    ElementType res = nodes[1].Data;
//    nodes[1].Data = nodes[heap->used_size].Data;
//    nodes[heap->used_size--].Data = 0;
//
//    int curr = 1;
//    int next = 2;
//    while (next <= heap->used_size) {
//        if (nodes[next].Data < nodes[curr].Data) {
//            swap(nodes + next, nodes + curr);
//            curr = next;
//            next *= 2;
//            //printf("\n%d %d\n", next, curr);
//        }
//        else if (nodes[next+1].Data < nodes[curr].Data) {
//            swap(nodes + next, nodes + curr);
//            curr = next + 1;
//            next = (next + 1)*2;
//        }
//        else {
//            break;
//        }
//    }
//
//
//}
int get_max_child(Heap* heap, int left, int right) {
    if (heap->used_size == left) return left;
    return (heap->nodes[left].Data < heap->nodes[right].Data) ? left : right;
}
// 데이터가 없을때는 -1 반환 (Underflow)
ElementType HEAP_Delete(Heap* heap) {
    HeapNode* nodes = heap->nodes;
    ElementType data = nodes[1].Data;
    nodes[1].Data = nodes[heap->used_size--].Data;
    int curr = 1;
    while (curr * 2 < heap->used_size) {
        int min_child = get_max_child(heap, curr * 2, curr * 2 + 1);
        if (nodes[curr].Data < nodes[min_child].Data) break;
        swap(nodes + min_child, nodes + curr);
        curr = min_child;
    }
    return data;
}

int main(void) {
    int Capacity, N;
    ElementType temp;
    Heap* minHeap = NULL;
    (void)freopen("pqdata.txt", "rt", stdin);
    (void)scanf("%d %d", &Capacity, &N);
    minHeap = HEAP_Create(Capacity + 1);
    for (int i = 0; i < N; ++i) {
        (void)scanf("%d", &temp);
        HEAP_Insert(minHeap, temp);
    }
    HEAP_PrintNodes(minHeap);
    HEAP_Delete(minHeap);
    HEAP_PrintNodes(minHeap);

    return 0;
}

#endif

/*
    //printf("%d %p\n", minHeap->capacity, minHeap->nodes);
        minHeap->nodes[0].Data = 10;
    printf("%d\n", minHeap->nodes[0].Data);

    HeapNode* arr = minHeap->nodes;
    arr[1].Data = 20;
    printf("%d\n", arr[1].Data);

*/