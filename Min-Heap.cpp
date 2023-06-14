#include <bits/stdc++.h>
using namespace std;

// Creating class "min-heap" using array
class MinHeap{
private:
    int *arr;
    int pos;

public:
    MinHeap(int size){
        arr = new int[size];
        pos = 0;
    }

    void insertHeap(int val){
        int idx = pos++;
        arr[idx] = val;

        while(idx > 0){
            int parent = (idx+1)/2 - 1;
            if(arr[idx] < arr[parent]){
                swap(arr[idx], arr[parent]);
                idx = parent;
            }
            else return; 
        }
    }

    void deleteHeap(){
        if(pos == 0){
            cout << "Heap is Empty" << endl;
            return;
        }

        int idx = 0;
        arr[idx] = arr[--pos];

        while(idx < pos){
            int leftChild = 2*idx + 1;
            int rightChild = 2*idx + 2;

            if((leftChild < pos && arr[idx] > arr[leftChild]) && (rightChild < pos && arr[idx] > arr[rightChild])){
                if(arr[leftChild] < arr[rightChild]){
                    swap(arr[idx], arr[leftChild]);
                    idx = leftChild;
                } 
                else{
                    swap(arr[idx], arr[rightChild]);
                    idx = rightChild;
                } 
            }
            else if(leftChild < pos && arr[idx] > arr[leftChild]){
                swap(arr[idx], arr[leftChild]);
                idx = leftChild;
            }
            else if(rightChild < pos && arr[idx] > arr[rightChild]){
                swap(arr[idx], arr[rightChild]);
                idx = rightChild;
            }
            else break;
        }
    }

    void printHeap(){
        for(int i=0; i<pos; i++){
            cout << arr[i] << " ";
        }
    }
};

void heapify(int *arr, int size, int idx){
    int smallest = idx;
    int leftChild = 2*idx + 1;
    int rightChild = 2*idx + 2;

    if((leftChild < size && arr[smallest] > arr[leftChild]) && (rightChild < size && arr[smallest] > arr[rightChild])){
        if(arr[leftChild] < arr[rightChild]) smallest = leftChild;
        else smallest = rightChild;
    }
    else if(leftChild < size && arr[smallest] > arr[leftChild]) smallest = leftChild;
    else if(rightChild < size && arr[smallest] > arr[rightChild]) smallest = rightChild;

    if(smallest != idx){
        swap(arr[smallest], arr[idx]);
        heapify(arr, size, smallest);
    }     
}

void heapSort(int *arr, int size){
    for(int i=(size/2)-1; i>=0; i--) heapify(arr, size, i);
    while(size > 0){
        heapify(arr, size, 0);
        swap(arr[0], arr[--size]);
    }
}

// Function to merge "k" sorted arrays
class MergeKSortedArray{
private:
    struct Node{
        int data;
        int row;
        int col;

        Node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };

    class compare{
    public:
        bool operator()(Node* node1, Node* node2){
            return node1->data > node2->data;
        }
    };

public:
    vector<int> mergeKSortedArray(vector<vector<int>> &vec, int k){
        vector<int> ans;
        priority_queue<Node*, vector<Node*>, compare> que;

        for(int i=0; i<k; i++){
            Node* nodeToInsert = new Node(vec[i][0], i, 0);
            que.push(nodeToInsert);
        }

        while(!que.empty()){
            Node* minNode = que.top();
            que.pop();

            int data = minNode->data;
            int row = minNode->row;
            int col = minNode->col;

            ans.push_back(data);
            if(col+1 < vec[row].size()){
                Node* nodeToInsert = new Node(vec[row][col+1], row, col+1);
                que.push(nodeToInsert);
            }
        }

        return ans;
    }
};
