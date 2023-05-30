#include <iostream>
using namespace std;

// Function to print Array
void printArray(int *arr, int size){
    for(int i=0; i<size; i++) cout << arr[i] << " ";
    cout << endl;
}

// Function to find the position of the given element using linear search
int linearSearch(int arr[], int size, int targetEle){
    for(int i=0; i<size; i++){
        if(arr[i] == targetEle) return i;
    }
    return -1;
}

// Function to find the position of the given element using binary search
int binarySearch(int arr[], int size, int targetEle){
    int start = 0;
    int end = size-1;
    while(start <= end){
        int middle = (start+end)/2;
        if(arr[middle] == targetEle) return middle;
        else if(arr[middle] < targetEle) start = middle + 1;
        else end = middle - 1;
    }
    return -1;
}

// Function to sort a given array using selection sort
void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minIdx = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Function to sort a given array using bubble sort
void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]) swap(arr[j+1], arr[j]);   
        }
    }
}

// Function to sort a given array using merge sort
class MergeSort{
private:
    void merge(int *arr, int start, int end){
        int mid = (start + end)/2;

        int len1 = mid - start + 1;
        int len2 = end - mid;

        int *firstArr = new int[len1];
        int *secondArr = new int[len2];

        int idx = start;
        for(int i=0; i<len1; i++) firstArr[i] = arr[idx++];

        idx = mid + 1;
        for(int i=0; i<len2; i++) secondArr[i] = arr[idx++];

        idx = start;
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < len1 && ptr2 < len2){
            if(firstArr[ptr1] < secondArr[ptr2]) arr[idx++] = firstArr[ptr1++];
            else arr[idx++] = secondArr[ptr2++];
        }

        while(ptr1 < len1) arr[idx++] = firstArr[ptr1++];

        while(ptr2 < len2) arr[idx++] = secondArr[ptr2++];
    }

    void solve(int* arr, int start, int end){
        if(start >= end) return;

        int mid = (start + end)/2;
        solve(arr, start, mid);
        solve(arr, mid+1, end);

        merge(arr, start, end);
    }

public:
    void mergeSort(int *arr, int size){
        int start = 0;
        int end = size - 1;
        solve(arr, start, end);
    }
};

// Function to insert an element in the given array
void insertion(int *arr, int &size, int val, int pos){
    for(int i=size; i>pos; i--) arr[i] = arr[i-1];
    arr[pos] = val;
    size++;
}

// Function to delete an element from the given array
void deletion(int *arr, int &size, int pos){
    for(int i=pos; i<size; i++) arr[i] = arr[i+1];
    size--;
}

// Function to find the max value present in the given array
int maxEle(int arr[], int size){
    int max = INT16_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

// Function to find the min value present in the given array
int minEle(int arr[], int size){
    int min = INT16_MAX;
    for(int i=0; i<size; i++){
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

// Function to find the middle element of the given array
int middleEle(int arr[], int size){
    int pos = size/2;
    return arr[pos];
}

// Function to find the max element till ith index
int* maxTillIdx(int *arr, int size){
    int* res = new int[size];
    int currMax = INT8_MIN;

    for(int i=0; i<size; i++){
        if(arr[i] > currMax){
            res[i] = arr[i];
            currMax = arr[i];
        }
        else res[i] = currMax; 
    }
    return res;    
}

// Function to find the sum of all subarrays present in the given array
void sumOfSubarrays(int *arr, int len){
    for(int i=0; i<len; i++){   
        for(int j=i; j<len; j++){
            int sum = 0;
            for(int k=i; k<=j; k++) sum = sum + arr[k];  
            cout << sum << " ";
        }
    }
}

// Function to find the len of the longest arthematic subarray 
int longestArthematicSubarray(int *arr, int len){
    int maxLen = 2;
    int currLen = 2;
    int diff = arr[1] - arr[0];

    for(int i=2; i<len; i++){
        if(arr[i] - arr[i-1] == diff) currLen++;
        else{
            diff = arr[i] - arr[i-1];
            currLen = 2;
        }
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}

// Function to find the first repeating element in the given array
int firstRepeatingEle(int *arr, int len){
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(arr[i] == arr[j]) return arr[i];
        }
    }
    return -1;
}

// Function to find the unique element from the given array
int findUnique(int *arr, int size){
    int ans = 0;
    for(int i=0; i<size; i++) ans = ans ^ arr[i];
    return ans;
}

// Function to find the first missing positive number in an array
int firstMissingPositive(int *arr, int len){
    for(int i=1; i<=len; i++){
    bool flag = false;
        for(int j=0; j<len; j++){
            if(arr[j] == i){
                flag = true;
                break;
            }
        }
        if(flag == false) return i;
    }
    return (len+1);
}

void swapAlternate(int *arr, int size){
    if(size % 2 == 0){
        for(int i=0; i<size; i+=2) swap(arr[i],arr[i+1]);
    }
    else{
        for(int i=0; i<size-1; i+=2) swap(arr[i],arr[i+1]);
    }
}
