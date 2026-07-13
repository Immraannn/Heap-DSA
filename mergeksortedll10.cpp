#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Comparator for Min Heap
class compare {
public:
    bool operator()(Node* a, Node* b) {
        // Min heap based on node data
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {

    // Min Heap
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Push first node of every linked list
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL)
            minHeap.push(lists[i]);
    }

    Node* head = NULL;
    Node* tail = NULL;

    // Process until heap becomes empty
    while (!minHeap.empty()) {

        // Get smallest node
        Node* temp = minHeap.top();
        minHeap.pop();

        // First node becomes head
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }

        // Push next node of extracted list
        if (temp->next != NULL)
            minHeap.push(temp->next);
    }

    return head;
}
