#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Heap node
class Node {
public:
    int data;      // Element value
    int row;       // Array number
    int col;       // Index within that array

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Comparator for Min Heap
class Compare {
public:
    bool operator()(Node* a, Node* b) {

        // Smallest value gets highest priority
        return a->data > b->data;
    }
};

// Function to merge K sorted arrays
vector<int> mergeKArrays(vector<vector<int>> &arr) {

    // Min Heap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    vector<int> ans;

    // Insert first element of every array
    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(new Node(arr[i][0], i, 0));
    }

    // Process until heap becomes empty
    while (!minHeap.empty()) {

        // Smallest element
        Node* temp = minHeap.top();
        minHeap.pop();

        // Store in answer
        ans.push_back(temp->data);

        int row = temp->row;
        int col = temp->col;

        // Push next element from same array (if exists)
        if (col + 1 < arr[row].size()) {
            minHeap.push(new Node(arr[row][col + 1], row, col + 1));
        }
    }

    return ans;
}

int main() {

    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    vector<int> ans = mergeKArrays(arr);

    cout << "Merged Array:\n";

    for (int x : ans)
        cout << x << " ";

    return 0;
}


Dry Run (Concise)

Input

A1 = {1,4,7}
A2 = {2,5,8}
A3 = {3,6,9}

Initial Heap

Heap	Answer
1,2,3	-
| Pop | Push | Heap After | Answer            |
| --- | ---- | ---------- | ----------------- |
| 1   | 4    | 2,3,4      | 1                 |
| 2   | 5    | 3,4,5      | 1,2               |
| 3   | 6    | 4,5,6      | 1,2,3             |
| 4   | 7    | 5,6,7      | 1,2,3,4           |
| 5   | 8    | 6,7,8      | 1,2,3,4,5         |
| 6   | 9    | 7,8,9      | 1,2,3,4,5,6       |
| 7   | —    | 8,9        | 1,2,3,4,5,6,7     |
| 8   | —    | 9          | 1,2,3,4,5,6,7,8   |
| 9   | —    | Empty      | 1,2,3,4,5,6,7,8,9 |

Final Answer
1 2 3 4 5 6 7 8 9



//   Why store (data, row, col)?
// We don't just need the value—we also need to know where it came from so we can insert the next element from the same array.
// For example:
// Heap Node = (2, 1, 0)
// means:
// data = 2
// row = 1 (second array)
// col = 0 (first element)
// After popping it, we know the next element to push is:
