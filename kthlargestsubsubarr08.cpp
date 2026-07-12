// Algorithm
// Generate all subarray sums.
// If heap size < k, push the sum.
// Otherwise:
// If current sum > heap top:
// Pop top.
// Push current sum.
// Finally, return heap.top().

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find kth largest subarray sum
int kthLargestSum(vector<int> &arr, int k) {

    // Min Heap to store k largest sums
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = arr.size();

    // Generate all possible subarrays
    for (int i = 0; i < n; i++) {

        int sum = 0;

        // Extend subarray from i to j
        for (int j = i; j < n; j++) {

            sum += arr[j];

            // Fill heap until size becomes k
            if (minHeap.size() < k) {
                minHeap.push(sum);
            }

            // Replace smallest if current sum is larger
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }

    // Top contains kth largest sum
    return minHeap.top();
}

int main() {

    vector<int> arr = {3, 2, 1};
    int k = 2;

    cout << "Kth Largest Subarray Sum = "
         << kthLargestSum(arr, k);

    return 0;
}
