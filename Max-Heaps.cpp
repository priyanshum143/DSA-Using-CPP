#include <bits/stdc++.h>
using namespace std;

// Struct "Node" for a heap
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Creating class "max-heap" using array
class MaxHeap{
private:
    int *arr;
    int pos;

public:
    MaxHeap(int size){
        arr = new int[size];
        pos = 0;
    }

    void insertHeap(int val){
        int idx = pos++;
        arr[idx] = val;

        while(idx > 0){
            int parent = (idx+1)/2 - 1;
            if(arr[idx] > arr[parent]){
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

            if((leftChild < pos && arr[idx] < arr[leftChild]) && (rightChild < pos && arr[idx] < arr[rightChild])){
                if(arr[leftChild] > arr[rightChild]){
                    swap(arr[idx], arr[leftChild]);
                    idx = leftChild;
                } 
                else{
                    swap(arr[idx], arr[rightChild]);
                    idx = rightChild;
                } 
            }
            else if(leftChild < pos && arr[idx] < arr[leftChild]){
                swap(arr[idx], arr[leftChild]);
                idx = leftChild;
            }
            else if(rightChild < pos && arr[idx] < arr[rightChild]){
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
    int largest = idx;
    int leftChild = 2*idx + 1;
    int rightChild = 2*idx + 2;

    if((leftChild < size && arr[largest] < arr[leftChild]) && (rightChild < size && arr[largest] < arr[rightChild])){
        if(arr[leftChild] > arr[rightChild]) largest = leftChild;
        else largest = rightChild;
    }
    else if(leftChild < size && arr[largest] < arr[leftChild]) largest = leftChild;
    else if(rightChild < size && arr[largest] < arr[rightChild]) largest = rightChild;

    if(largest != idx){
        swap(arr[largest], arr[idx]);
        heapify(arr, size, largest);
    }     
}

void heapSort(int* arr, int size){
    for(int i=(size/2)-1; i>=0; i--) heapify(arr, size, i);
    while(size > 0){
        heapify(arr, size, 0);
        swap(arr[0], arr[--size]);
    }
}

// Function to find if a binary tree if a max-heap or not 
class IsHeap{
private:
    int countNodes(Node* root){
        if(root == NULL) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1; 
    }
    
    bool isCBT(Node* root, int index, int totalCount){
        if(root == NULL) return true;
        
        if(index >= totalCount) return false;
        
        bool left = isCBT(root->left, 2*index+1, totalCount);
        bool right = isCBT(root->right, 2*index+2, totalCount);
        return left && right;
    }
    
    bool isMaxOrder(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        else if(root->right == NULL) return (root->data > root->left->data);
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return ( (left && right) && (root->data > root->left->data && root->data > root->right->data));
        }
    }

public:
    bool isHeap(Node* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root, index, totalCount) && isMaxOrder(root)) return true;
        return false;
    }
};

// Function to convert a BST into  Max-Heap
class BSTToMaxHeap{
private:
    void inorder(Node* root, vector<int> &inorderVec){
        if(root == NULL) return;

        inorder(root->left, inorderVec);
        inorderVec.push_back(root->data);
        inorder(root->right, inorderVec);
    }

    void solve(Node* root, vector<int> &inorderVec, int &idx){
        if(root == NULL) return;

        solve(root->left, inorderVec, idx);
        solve(root->right, inorderVec, idx);
        root->data = inorderVec[idx++];
    }

public:
    void convertToMaxHeap(Node* root){
        vector<int> inorderVec;
        inorder(root, inorderVec);

        int idx = 0;
        solve(root, inorderVec, idx);
    }
};
