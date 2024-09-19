#include <stdio.h>
#include <stdlib.h>

// Structure to represent the Max Heap
struct MaxHeap {
    int *arr;
    int size;
    int capacity;
};

// Function to create a heap of a given capacity
struct MaxHeap* createHeap(int capacity) {
    struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

// Function to get the parent index of a node
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the left child index of a node
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the right child index of a node
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to insert a new element into the heap
void insert(struct MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new element at the end
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = value;

    // Fix the Max Heap property by comparing with the parent and swapping
    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;

        i = parent(i);
    }
}

// Heapify the root element downwards
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

// Function to extract the maximum element (root) from the heap
int extractMax(struct MaxHeap* heap) {
    if (heap->size <= 0)
        return -1; // Empty heap

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Store the max value
    int max = heap->arr[0];

    // Move the last element to the root
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify the root element to maintain the max heap property
    heapify(heap, 0);

    return max;
}

// Function to extract a specific value from the heap
int extractValue(struct MaxHeap* heap, int value) {
    int i;
    // Find the index of the value in the heap
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i] == value)
            break;
    }

    if (i == heap->size) {
        printf("Value not found in the heap\n");
        return -1;
    }

    // Swap with the last element
    int extractedValue = heap->arr[i];
    heap->arr[i] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify down and up to maintain max heap property
    heapify(heap, i);

    // In case the swapped element is larger than its parent, heapify upwards
    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;
        i = parent(i);
    }

    return extractedValue;
}

// Function to display the heap elements
void printHeap(struct MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Main function to test the Max Heap implementation
int main() {
    // Create a Max Heap of capacity 10
    struct MaxHeap* heap = createHeap(11);

    // Insert elements into the heap
    insert(heap, 70);
    insert(heap, 60);
    insert(heap, 40);
    insert(heap, 45);
    insert(heap, 50);
    insert(heap, 39);
    insert(heap, 16);
    insert(heap, 10);
    insert(heap, 9);
    insert(heap, 35);
    insert(heap, 5);

    printf("Heap elements after insertion: ");
    printHeap(heap);

    // Extract a specific value
    // int valueToExtract = 10;
    // printf("Extracted value %d from the heap\n", valueToExtract);
    // extractValue(heap, valueToExtract);
    // printf("Heap elements after extracting value: ");
	extractMax(heap);
    printHeap(heap);

    // Free the memory allocated for the heap
    free(heap->arr);
    free(heap);

    return 0;
}
