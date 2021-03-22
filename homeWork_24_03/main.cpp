#include <iostream>

using namespace std;

void Switch(int * a, int * b){
    int bridge = *a;
    *a = *b;
    *b = bridge;
}

struct MaxHeap {

 int * array = 0;
 int size = 0;
 int maxSize = 0;

 MaxHeap(int size) {
     array = new int[size];
     maxSize = size;
 }

 int Parent(int i) {
     if(i == 0){
        return -1;
     }
     return (i-1)/2;
 }

 int LeftChild(int i) {
    return 2*i + 1;
 }

 int RightChild(int i) {
    return 2*i + 2;
 }

 int GetMax() {
    return *array;
 }

 void SiftUp(int i) {
    while((array[Parent(i)] < array[i])) {
            Switch(&array[Parent(i)], &array[i]);
            i = Parent(i);
            if(i == 0){
                break;
            }
        }
 }

 void SiftDown(int i) {
     int left = LeftChild(i);
     int right = RightChild(i);
     int biggest = i;

        if((left < size) && (array[left] > array[i])) {
            biggest = left;
        }

        if((right < size) && (array[right] > array[left])) {
            biggest = right;
        }

        if(biggest != i){
            Switch(&array[i], &array[biggest]);
            SiftDown(biggest);
        }
 }

 void Insert(int p) {

    if(size == 0) {
        array[size] = p;
        size++;
        return;
    }

    if(size < maxSize) {
        array[size] = p;

        SiftUp(size);

        size++;
        return;
    }

    cout<<"Error! Heap is full!"<<endl;
 }

 int ExtractMax() {
    if(size == 1) {
        size--;
        return array[0];
    }

    if((size != 0) && (maxSize != 0)){
        int maxNum = array[0];
        array[0] = array[size - 1];
        size--;

        SiftDown(0);

        return maxNum;
    }

    cout<<"Heap is empty"<<endl;
    return -1;
 }

};


void HeapSort(int * arr, int * b, int size){
    MaxHeap * heap = new MaxHeap(size);

    for(int i = 0; i < size; i++) {
        heap->Insert(arr[i]);
    }

    for(int j = 0; j < size; j++) {
        b[j] = heap->ExtractMax();
    }

    delete heap;
}

int main()
{
    MaxHeap * heap = new MaxHeap(14);

    heap->Insert(2);
    heap->Insert(8);
    heap->Insert(2);
    heap->Insert(8);
    heap->Insert(9);
    heap->Insert(3);
    heap->Insert(0);
    heap->Insert(4);


    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;
    cout<<heap->ExtractMax()<<endl;


    cout<<"New task!"<<endl;
    int a[8]={2,8,2,8,9,3,0,4};
    int v[8];

    HeapSort(a, v, 8);

    for(int w = 0; w < 8; w++){
        cout<<v[w]<<endl;
    }

    delete heap;
    return 0;
}
