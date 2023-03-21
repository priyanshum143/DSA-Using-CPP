#include <iostream>
using namespace std;

class minHeap{
private:
    int arr[100];
    int size;

public:
    minHeap(){
        size = 0;
    }

    void insertion(int val){
        int idx = size;
        arr[idx] = val;
        size++;

        while(idx > 0){
            int parent = (idx-1)/2;
            if(arr[parent] > arr[idx]){
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){
        if(size == 0){
            cout << "Heap is Empty" << endl;
            return;
        }

        size--;
        arr[0] = arr[size];

        int idx = 0;
        while(idx < size){
            int leftIndex = 2*idx + 1;
            int rightIndex = 2*idx + 2;

            if(leftIndex < size && rightIndex < size && arr[idx] > arr[leftIndex] && arr[idx] > arr[rightIndex]){
                if(arr[leftIndex] < arr[rightIndex]){
                    swap(arr[idx], arr[leftIndex]);
                    idx = leftIndex;
                }
                else{
                    swap(arr[idx], arr[rightIndex]);
                    idx = rightIndex;
                }
            }
            else if(leftIndex < size && arr[idx] > arr[leftIndex]){
                swap(arr[idx], arr[leftIndex]);
                idx = leftIndex;
            }
            else if(rightIndex < size && arr[idx] > arr[rightIndex]){
                swap(arr[idx], arr[rightIndex]);
                idx = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void printHeap(){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int idx){
    int smallest = idx;
    int leftIdx = 2*idx + 1;
    int rightIdx = 2*idx + 2;

    if(leftIdx < size && rightIdx < size && arr[smallest] > arr[leftIdx] && arr[smallest] > arr[rightIdx]){
        if(arr[leftIdx] < arr[rightIdx]){
            smallest = leftIdx;
        }
        else{
            smallest = rightIdx;
        }
    }
    else if(leftIdx < size && arr[smallest] > arr[leftIdx]){
        smallest = leftIdx;
    }
    else if(rightIdx < size && arr[smallest] > arr[rightIdx]){
        smallest = rightIdx;
    }

    if(smallest != idx){
        swap(arr[smallest], arr[idx]);
        heapify(arr, size, smallest);
    }
}

void heapSort(int arr[], int size){
    int n = size - 1;
    while(n > 0){
        swap(arr[0], arr[n]);
        n--;
        heapify(arr, n, 0);
    }
}

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i=0; i<size; i++) cin >> arr[i];

    cout << "Building a heap => ";
    for(int i=(size-1)/2; i>=0; i--) heapify(arr, size, i);
    for(int i=0; i<size; i++) cout << arr[i] << " ";

    cout << endl;

    cout << "Sorting the given heap = > ";
    heapSort(arr, size);
    for(int i=0; i<size; i++) cout << arr[i] << " ";

}