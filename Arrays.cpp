#include <iostream>
using namespace std;

void printArray(int *arr, int size){
    for(int i=0; i<size; i++) cout << arr[i] << " ";
    cout << endl;
}

int linearSearch(int arr[], int size, int targetEle){
    for(int i=0; i<size; i++){
        if(arr[i] == targetEle){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int targetEle){
    int start = 0;
    int end = size-1;
    while(start <= end){
        int middle = (start+end)/2;
        if(arr[middle] == targetEle){
            return middle;
        }
        else if(arr[middle] < targetEle){
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }
    return -1;
}

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minIdx = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]) swap(arr[j+1], arr[j]);   
        }
    }
}

void insertion(int *arr, int &size, int val, int pos){
    for(int i=size; i>pos; i--) arr[i] = arr[i-1];
    arr[pos] = val;
    size++;
}

void deletion(int *arr, int &size, int pos){
    for(int i=pos; i<size; i++) arr[i] = arr[i+1];
    size--;
}

int maxEle(int arr[], int size){
    int max = INT16_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int minEle(int arr[], int size){
    int min = INT16_MAX;
    for(int i=0; i<size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int middleEle(int arr[], int size){
    int pos = size/2;
    return arr[pos];
}

void maxTillIdx(int *arr, int len){
    int res[len];
    int currMax = INT8_MIN;

    for(int i=0; i<len; i++){
        if(arr[i] > currMax){
            res[i] = arr[i];
            currMax = arr[i];
        }
        else{
            res[i] = currMax;
        }
    }

    for(int i=0; i<len; i++){
        cout << res[i] << " ";
    }
}

void sumOfSubarrays(int *arr, int len){
    for(int i=0; i<len; i++){   
        for(int j=i; j<len; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum = sum + arr[k];  
            }
            cout << sum << " ";
        }
    }
}

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

int firstRepeatingEle(int *arr, int len){
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(arr[i] == arr[j]){
                return i;
            }
        }
    }
    return -1;
}

int findUnique(int *arr, int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

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
