// Heapify Algorithm (Max Heap)
// Heapify is used to restore the Max Heap property when a node violates it.
// Max Heap Property: Every parent node must be greater than or equal to its children.

// Function to convert a subtree into a Max Heap
void heapify(int arr[], int n, int i) {

    // Assume current node is the largest
    int largest = i;

    // Left child index
    int left = 2 * i;

    // Right child index
    int right = 2 * i + 1;

    // Check if left child exists and is larger
    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child exists and is larger
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the current node
    if (largest != i) {

        // Swap parent with the larger child
        swap(arr[largest], arr[i]);

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Build Max Heap from any random array

// Why start from n/2?
// Because:
// Nodes from n/2 + 1 to n are leaf nodes.
// Leaf nodes are already heaps (they have no children).
// Only internal (non-leaf) nodes need heapification.
for (int i = n / 2; i >= 1; i--) {
    heapify(arr, n, i);
}
