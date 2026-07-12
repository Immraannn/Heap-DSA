#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[], int n, int i) {

    int largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {

    // Build Max Heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    int size = n;

    while (size > 1) {

        // Put maximum element at the end
        swap(arr[1], arr[size]);

        // Reduce heap size
        size--;

        // Restore Max Heap
        heapify(arr, size, 1);
    }
}

int main() {

    // 1-based indexing
    int arr[] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    heapSort(arr, n);

    cout << "Sorted Array: ";

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    return 0;
}
