#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
    int *arr;
    int size;
    int capacity;
};

struct MaxHeap* createHeap(int capacity) {
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void insert(struct MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = value;

    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;

        i = parent(i);
    }
}

void heapify(struct MaxHeap* heap, int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != i) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = temp;

        heapify(heap, largest);
    }
}

int extractMax(struct MaxHeap* heap) {
    if (heap->size <= 0)
        return -1; 

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }


    int max = heap->arr[0];

    // Move the last element to the root
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify the root element to maintain the max heap property
    heapify(heap, 0);

    return max;
}

void printHeap(struct MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}


int main() {

    struct MaxHeap* heap = createHeap(10);

 
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 40);

    printf("Heap elements after insertion: ");
    printHeap(heap);

    
    printf("Extracted max: %d\n", extractMax(heap));
    printf("Heap elements after extracting max: ");
    printHeap(heap);


    free(heap->arr);
    free(heap);

    return 0;
}
