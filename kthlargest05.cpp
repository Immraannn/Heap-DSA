#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find kth largest element
int kthLargest(vector<int> &arr, int k) {

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Step 1: Insert first k elements
    for (int i = 0; i < k; i++) {
        minHeap.push(arr[i]);
    }

    // Step 2: Traverse remaining elements
    for (int i = k; i < arr.size(); i++) {

        // If current element is larger than the smallest in heap
        if (arr[i] > minHeap.top()) {

            // Remove the smallest among current k largest
            minHeap.pop();

            // Insert current larger element
            minHeap.push(arr[i]);
        }
    }

    // Top contains the kth largest element
    return minHeap.top();
}

int main() {

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout << "Kth Largest Element = " << kthLargest(arr, k);

    return 0;
}
