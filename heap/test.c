#include <stdio.h>
#include <stdlib.h>
typedef struct MaxHeap
{
    int *arr;
    int size;
    int capacity;
} heap;
heap *createHeap(int capacity)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->arr = (int *)malloc(sizeof(int) * capacity);
    return h;
}
int parent(int i)
{
    return (i - 1) / 2;
}
void insert(heap *h, int value)
{
    if (h->size == h->capacity)
    {
        printf("Heap overflow\n");
        return;
    }
    h->size++;
    int i = h->size - 1;
    h->arr[i] = value;
    // printf("%d\n", i);

    while (i != 0 && h->arr[parent(i)] < h->arr[i])
    {
        int temp=h->arr[i];
        h->arr[i]=h->arr[parent(i)];
        h->arr[parent(i)]=temp;
        i=parent(i);
    }
}

void printHeap(heap* h)
{
    for(int i=0;i<h->size;i++)
    {
        printf("%d ",h->arr[i]);
    }
    printf("\n");
}
int leftChild(int i)
{
 return 2*i+1;
}
int rightChild(int i)
{
 return 2*i+2;
}
void heapify(heap* h,int i)
{
    int left=leftChild(i);
    int right =leftChild(i);
    int largest=i;
    if(left <h->size && h->arr[left]>h->arr[largest])
    {
        largest=left;
    }
    if(right<h->size && h->arr[right]>h->arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=h->arr[i];
        h->arr[i]=h->arr[largest];
        h->arr[largest]=temp;
        heapify(h,largest);
    }
}
int extractMax(heap* h)
{
    if(h->size<=0)
    {
        return -1;
    }
    if(h->size==1)
    {
        h->size--;
        return h->arr[0];
    }

    int max=h->arr[0];
    h->arr[0]=h->arr[h->size-1];
    h->size--;
    heapify(h,0);
    return max;
}


int main()
{
    heap *h = createHeap(9);
    // insert(h, 70);
    // insert(h, 40);
    // insert(h, 45);
    // insert(h, 50);
    // insert(h, 39);
    // insert(h, 16);
    // insert(h, 10);
    // insert(h, 9);
    // insert(h, 35);
    // insert(h, 60);
    // insert(h, 5);
    insert(h,50);
    insert(h,45);
    insert(h,35);
    insert(h,33);
    insert(h,16);
    insert(h,25);
    insert(h,34);
    insert(h,12);
    insert(h,10);
    printHeap(h);
    printf("max element  from hea is : %d",extractMax(h));
    printf("\n");
    printHeap(h);
    return 0;
}