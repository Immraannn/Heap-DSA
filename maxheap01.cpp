#include <iostream>
using namespace std;

class Heap {

public:
    // Heap array
    // Index 0 is unused
    int arr[100];

    // Current number of elements in heap
    int size;

    // Constructor
    Heap() {
        arr[0] = -1;   // Dummy value
        size = 0;
    }

    // Insert a new element into the heap
    void insert(int value) {

        // Step 1: Insert at the last position
        size = size + 1;
        int index = size;
        arr[index] = value;

        // Step 2: Place the element at its correct position
        while (index > 1) {

            int parent = index / 2;

            // If parent is smaller, swap
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                // Heap property satisfied
                return;
            }
        }
    }

    // Delete the root element (maximum element)
    void deleteFromHeap() {

        // Heap is empty
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];

        // Step 2: Remove last element
        size--;

        // Step 3: Move root to its correct position
        int i = 1;

        while (i <= size) {

            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            // If left child is larger
            if (leftIndex <= size && arr[leftIndex] > arr[i]) {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }

            // Else if right child is larger
            else if (rightIndex <= size && arr[rightIndex] > arr[i]) {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }

            // Heap property satisfied
            else {
                return;
            }
        }
    }

    // Print heap elements
    void print() {

        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap:" << endl;
    h.print();

    h.deleteFromHeap();

    cout << "After deletion:" << endl;
    h.print();

    return 0;
}

//       55
//      /  \
//    54    53
//   /  \
// 50   52
