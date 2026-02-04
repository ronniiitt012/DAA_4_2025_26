#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i) {

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heapSize && heap[smallest] > heap[left]) 
        smallest = left;

    if(right < heapSize && heap[smallest] > heap[right]) 
        smallest = right;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {

    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i = (i-1)/2;
    }
}

void insert(int val) {

    if(heapSize == MAX) {
        cout<<"Overflow\n";
        return;
    }

    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

void deleteNode() {

    if(heapSize == 0) {
        cout<<"No element\n";
        return;
    }

    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}
bool searchHeap(int key) {
    for(int i = 0; i < heapSize; i++) {
        if(heap[i] == key)
            return true;
    }
    return false;
}
int main() {
    insert(2);
    insert(1);
    insert(0);
    if(searchHeap(1))
        cout<<"Element Found\n";
    else
        cout<<"Element Not Found\n";
    deleteNode();
    deleteNode();
    cout<<"Heap elements: ";
    for(int i = 0; i < heapSize; i++)
        cout<<heap[i]<<" ";
}
