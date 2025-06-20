//  maxHeap / minHeap 모두 되는
#if 01
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

void HEAP_PrintNodes(Heap* heap) {
	for (int i = 1; i <= heap->used_size; ++i) {
		printf("%d ", heap->nodes[i].Data);
	}
	printf("\n");
}
int comp_max(int parent_data, int child_data) {
	return parent_data < child_data;
}
int comp_min(int parent_data, int child_data) {
	return parent_data > child_data;
}
typedef int (*Comp_t) (int, int);
void HEAP_Insert(Heap* heap, ElementType newData, Comp_t comp_func) {
	int curr = ++heap->used_size;
	HeapNode* nodes = heap->nodes;

	heap->nodes[curr].Data = newData;
	int parent = curr / 2;
	while ((parent > 0) && comp_func(nodes[parent].Data, nodes[curr].Data)) {
		swap(nodes + parent, nodes + curr);
		curr = parent;
		parent /= 2;
	}
}

int get_child(Heap* heap, int left, int right, Comp_t comp_func) {
	if (heap->used_size == left) return left;
	return comp_func(heap->nodes[right].Data, heap->nodes[left].Data) ? left : right;
}

// 데이터가 없을때는 -1 반환 (Underflow)
ElementType HEAP_Delete(Heap* heap, Comp_t comp_func) {
	HeapNode* nodes = heap->nodes;
	ElementType data = nodes[1].Data;
	nodes[1].Data = nodes[heap->used_size--].Data;
	int curr = 1;
	while (curr * 2 < heap->used_size) {
		int min_child = get_child(heap, curr * 2, curr * 2 + 1, comp_func);
		if (comp_func(nodes[min_child].Data, nodes[curr].Data)) break;
		swap(nodes + min_child, nodes + curr);
		curr = min_child;
	}
	return data;
}

int main(void) {
	int Capacity, N;
	ElementType temp;
	Heap* heap = NULL;
	(void)freopen("pq_data.txt", "rt", stdin);
	(void)scanf("%d %d", &Capacity, &N);
	heap = HEAP_Create(Capacity + 1);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", &temp);
		HEAP_Insert(heap, temp, comp_max);
	}
	HEAP_PrintNodes(heap);
	for (int i = 0; i < N; ++i) {
		printf("%d\n", HEAP_Delete(heap, comp_max));
	}
	return 0;
}
#endif
