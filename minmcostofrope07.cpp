// We need to connect all ropes into one rope with minimum total cost.
// The rule is:
// Always connect the two smallest ropes first.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find minimum cost of connecting ropes
int minCost(vector<int> &ropes) {

    // Create a Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all rope lengths into the Min Heap
    for (int rope : ropes) {
        minHeap.push(rope);
    }

    int cost = 0;

    // Continue until only one rope remains
    while (minHeap.size() > 1) {

        // Take two smallest ropes
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        // Cost of connecting them
        int sum = first + second;

        // Add to total cost
        cost += sum;

        // Push newly formed rope back into heap
        minHeap.push(sum);
    }

    return cost;
}

int main() {

    vector<int> ropes = {4, 3, 2, 6};

    cout << "Minimum Cost = " << minCost(ropes);

    return 0;
}
// output
// Minimum cost =29

| Step  | Ropes taken | New rope | Cost added | Total cost | Heap after  |
| ----- | ----------- | -------: | ---------: | ---------: | ----------- |
| Start | —           |        — |          — |          0 | `{2,3,4,6}` |
| 1     | 2 + 3       |        5 |          5 |          5 | `{4,5,6}`   |
| 2     | 4 + 5       |        9 |          9 |         14 | `{6,9}`     |
| 3     | 6 + 9       |       15 |         15 |     **29** | `{15}`      |

