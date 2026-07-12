#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to find kth smallest element
int kthSmallest(vector<int> &arr, int k) {

    // Max Heap
    priority_queue<int> maxHeap;

    // Step 1: Insert first k elements
    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }

    // Step 2: Traverse remaining elements
    for (int i = k; i < arr.size(); i++) {

        // If current element is smaller than heap's largest
        if (arr[i] < maxHeap.top()) {

            // Remove largest among current k smallest
            maxHeap.pop();

            // Insert current smaller element
            maxHeap.push(arr[i]);
        }
    }

    // Top contains kth smallest element
    return maxHeap.top();
}

int main() {

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout << "Kth Smallest Element = " << kthSmallest(arr, k);

    return 0;
}


Dry Run (Concise Table)

Array: {7, 10, 4, 3, 20, 15}
k = 3

Step	Current Element	Heap (Max Heap)	Action
1	7	[7]	Push
2	10	[10, 7]	Push
3	4	[10, 7, 4]	Push first k elements
4	3	[7, 4, 3]	3 < 10 → Pop 10, Push 3
5	20	[7, 4, 3]	20 > 7 → Ignore
6	15	[7, 4, 3]	15 > 7 → Ignore
