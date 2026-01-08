#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class Sorting {
private:

public:
    void selectionSort(int *arr, int len) {
        for (int i=0; i<len; i++) {
            int min = INT_MAX, idx = i;
            for (int j=i; j<len; j++) {
                if (arr[j] < min) {
                    min = arr[j];
                    idx = j;
                }
            }
            swap(arr[i], arr[idx]);
        }
    }

    void bubbleSort(int *arr, int len) {
        for (int i=len-1; i>=0; i--) {
            // To check if any swap happens, if not then the array is sorted
            bool swapStatus = false;

            for (int j=0; j<i; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapStatus = true;
                }
            }

            if (swapStatus == false) {
                // cout << "No swap happened in iteration " << (len - i) << ", Hence array is sorted\n";
                return;
            }
        }
    }

    void insertionSort(int *arr, int len) {
        for (int i=1; i<len; i++) {
            int keyEle = arr[i];
            
            int j = i - 1;
            while (j >= 0 && arr[j] > keyEle) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = keyEle;
        }
    }
};

class Utils{
public:
    static void printArray(int *arr, int len) {
        for (int i=0; i<len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    static void inputArray(int *arr, int len) {
        for (int i=0; i<len; i++) cin >> arr[i];
    }
};

int main() {
    // Asking user to choose one sorting technique
    int choice;
    cout << "Which sorting technique you want to choose.\n";
    cout << "Press 1 for [Selection Sort]\n";
    cout << "Press 2 for [Bubble Sort]\n";
    cout << "Press 3 for [Insertion Sort]\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Taking user input for array's length and the array's elements
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;

    int *arr = new int[len];
    cout << "Enter " << len << " elements of the array\n";
    Utils::inputArray(arr, len);

    // Creating object for soring
    Sorting sort = Sorting();

    // Applying the user's choosen sorting technique on the given array
    switch (choice) {
    case 1: {
        auto startTime = steady_clock::now();
        sort.selectionSort(arr, len);
        auto endTime = steady_clock::now();
        auto duration = duration_cast<nanoseconds>(endTime - startTime);
        cout << "Selection Sort took: " << duration.count() << " nanoseconds\n";
        break;
    }

    case 2: {
        auto startTime = steady_clock::now();
        sort.bubbleSort(arr, len);
        auto endTime = steady_clock::now();
        auto duration = duration_cast<nanoseconds>(endTime - startTime);
        cout << "Bubble Sort took: " << duration.count() << " nanoseconds\n";
        break;
    }

    case 3: {
        auto startTime = steady_clock::now();
        sort.insertionSort(arr, len);
        auto endTime = steady_clock::now();
        auto duration = duration_cast<nanoseconds>(endTime - startTime);
        cout << "Insertion Sort took: " << duration.count() << " nanoseconds\n";
        break;
    }

    default:
        break;
    }

    // Printing the sorted array
    Utils::printArray(arr, len);
}