#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    bool isMaxHeap;  // true = max-heap, false = min-heap

    // Helper function to maintain heap property (heapify up)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        if (index && compare(heap[index], heap[parent])) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Helper function to maintain heap property (heapify down)
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int extreme = index;

        if (left < heap.size() && compare(heap[left], heap[extreme]))
            extreme = left;

        if (right < heap.size() && compare(heap[right], heap[extreme]))
            extreme = right;

        if (extreme != index) {
            swap(heap[index], heap[extreme]);
            heapifyDown(extreme);
        }
    }

    // Comparison function based on heap type
    bool compare(int a, int b) {
        return isMaxHeap ? a > b : a < b;
    }

public:
    // Constructor
    PriorityQueue(bool maxHeap = true) {
        isMaxHeap = maxHeap;
    }

    // Insert an element
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Get top element (max or min)
    int getTop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Remove top element
    void extractTop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Check if empty
    bool isEmpty() {
        return heap.empty();
    }

    // Get size
    int size() {
        return heap.size();
    }

    // Display the heap
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << "\n";
    }
};

int main() {
    cout << "Max-Heap Priority Queue:\n";
    PriorityQueue maxPQ(true); // Max-heap
    maxPQ.insert(10);
    maxPQ.insert(40);
    maxPQ.insert(20);
    maxPQ.insert(30);

    maxPQ.display();
    cout << "Top element: " << maxPQ.getTop() << "\n";
    maxPQ.extractTop();
    cout << "After removing top: ";
    maxPQ.display();

    cout << "\nMin-Heap Priority Queue:\n";
    PriorityQueue minPQ(false); // Min-heap
    minPQ.insert(10);
    minPQ.insert(40);
    minPQ.insert(20);
    minPQ.insert(30);

    minPQ.display();
    cout << "Top element: " << minPQ.getTop() << "\n";
    minPQ.extractTop();
    cout << "After removing top: ";
    minPQ.display();

    return 0;
}
