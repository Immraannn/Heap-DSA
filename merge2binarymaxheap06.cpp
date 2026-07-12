#include <iostream>
#include <vector>
using namespace std;

// Heapify function for Max Heap
void heapify(vector<int> &arr, int n, int i) {

    int largest = i;          // Assume current node is largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not current node
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Heapify affected subtree
        heapify(arr, n, largest);
    }
}

// Function to merge two Max Heaps
vector<int> mergeHeaps(vector<int> &a, vector<int> &b) {

    vector<int> ans;

    // Step 1: Copy first heap
    for (int x : a)
        ans.push_back(x);

    // Step 2: Copy second heap
    for (int x : b)
        ans.push_back(x);

    int n = ans.size();

    // Step 3: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(ans, n, i);
    }

    return ans;
}

int main() {

    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};

    vector<int> ans = mergeHeaps(heap1, heap2);

    cout << "Merged Max Heap:\n";

    for (int x : ans)
        cout << x << " ";

    return 0;
}
//final heap
  //       12
  //     /    \
  //   10      9
  //  /  \    / \
  // 2    5  7   6


// Great question. The reason we start heapifying from the last non-leaf node is because leaf nodes are already valid heaps.
// Why?
// A heap satisfies:
// Every parent is greater than or equal to its children (Max Heap).
// A leaf node has no children.
// Since a leaf node has no children, it already satisfies the heap property. There is nothing to fix.
// So, heapifying a leaf node is unnecessary.
