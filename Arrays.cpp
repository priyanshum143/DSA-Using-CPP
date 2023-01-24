#include <iostream>
using namespace std;

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
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

void insertion(int arr[], int size, int val, int pos){
    for(int i=size; i>pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;

    for(int i=0; i<=size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deletion(int arr[], int size, int pos){
    for(int i=pos; i<size; i++){
        arr[i] = arr[i+1];
    }

    for(int i=0; i<size-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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