/******************************************************************************
Binary Heap
*******************************************************************************/
#include <stdio.h>
#include <climits>
#include<iostream>

using namespace std;

class MinHeap{
    int *arr;
    int capacity;
    int size;
    
    public:
    MinHeap(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        this->size = 0;
    }
    
    int getMin(){return arr[0];}
    int parent(int i){return (i-1)/2;}
    int left (int i){return (2*i+1);}
    int right (int i){return (2*i+2);}
    
    
    void Heapify(int index);
    int extractMin();
    void insertVal(int val);
    void deleteVal(int index);
    void decreaseVal(int index, int newVal);
    
};
void swap(int &n1, int &n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void MinHeap::Heapify(int index){
    int l = left(index);
    int r = right(index);
    int small = index;
    
    if(l < size && arr[l] < arr[index])
        small = l;
    if(r < size && arr[r] < arr[small]){
        small = r;
    }
    if(small != index){
        swap(arr[index], arr[small]);
        Heapify(small);
    }
}

int MinHeap::extractMin(){
    if(size <= 0)
        return INT_MAX;
    else if(size == 1){
        size--;
        return arr[0];
    }
    
    int min = arr[0];
    arr[0] = arr[size-1];
    size--;
    
    Heapify(0);
    return min;
    
}

void MinHeap::decreaseVal(int index, int newVal){
    arr[index] = newVal;
    
    while(index!=0 && arr[parent(index)] > arr[index]){
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}

void MinHeap::deleteVal(int index){
    decreaseVal(index, INT_MIN);
    extractMin();
}

void MinHeap::insertVal(int val){
    if (size == capacity)
    {
        cout << "\nOverflow: Could not insert\n";
        return;
    }

    size++;
    int index = size-1;
    arr[index] = val;
    
    while(index!=0 && arr[parent(index)]>arr[index]){
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}

int main()
{
    MinHeap h(11);
    h.insertVal(3);
    h.insertVal(2);
    h.deleteVal(1);
    h.insertVal(15);
    h.insertVal(5);
    h.insertVal(4);
    h.insertVal(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseVal(2, 1);
    cout << h.getMin();
    return 0;
}