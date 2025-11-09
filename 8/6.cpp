#include <iostream>
#include <vector>
using namespace std;

/* ==============================================================
   🧠 PRIORITY QUEUE (USING HEAP)
   ==============================================================
   ETHOS:
   - A Priority Queue is a special kind of queue where
     each element has a priority value.
   - Elements with higher priority are served before others.
   - We use a MAX HEAP to implement it efficiently.
   - Heap ensures:
        parent >= children  (for max heap)
   - Fast operations:
        Insert → O(log n)
        Get Max → O(1)
        Extract Max → O(log n)
   ============================================================== */

/* --------------------------------------------------------------
   🧩 heapify()
   - Fixes the max-heap property starting from node i
   - Assumes its children are already heaps
   - If a child is larger than the parent, swap and recurse
   -------------------------------------------------------------- */
void heapify(vector<int> &heap, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

/* --------------------------------------------------------------
   insert(x)
   - Adds a new element (x) to the heap.
   - Steps:
       1. Push x at end
       2. Bubble up till heap property restored
   - Time: O(log n)
   -------------------------------------------------------------- */
void insert(vector<int> &heap, int x) {
    heap.push_back(x);
    int i = heap.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else break;
    }
}

/* --------------------------------------------------------------
   getMax()
   - Returns the element with the highest priority (root)
   - Time: O(1)
   -------------------------------------------------------------- */
int getMax(const vector<int> &heap) {
    if (heap.empty()) {
        cout << "Heap is empty\n";
        return -1;
    }
    return heap[0];
}

/* --------------------------------------------------------------
   extractMax()
   - Removes and returns the highest priority element
   - Steps:
       1. Save root (max element)
       2. Move last element to root
       3. Reduce size
       4. Heapify(0)
   - Time: O(log n)
   -------------------------------------------------------------- */
int extractMax(vector<int> &heap) {
    if (heap.empty()) {
        cout << "Heap is empty\n";
        return -1;
    }

    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, heap.size(), 0);
    return maxVal;
}

/* --------------------------------------------------------------
   increaseKey(i, newVal)
   - Increases the priority (value) of an element at index i
   - Steps:
       1. Replace old value with newVal
       2. Bubble up till heap property restored
   - Time: O(log n)
   -------------------------------------------------------------- */
void increaseKey(vector<int> &heap, int i, int newVal) {
    if (i >= heap.size() || newVal < heap[i]) {
        cout << "Invalid operation\n";
        return;
    }

    heap[i] = newVal;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else break;
    }
}

/* --------------------------------------------------------------
   MAIN FUNCTION — demo of all operations
   -------------------------------------------------------------- */
int main() {
    vector<int> pq;

    insert(pq, 10);
    insert(pq, 40);
    insert(pq, 20);
    insert(pq, 30);
    insert(pq, 50);

    cout << "Initial Priority Queue (Max Heap): ";
    for (int x : pq) cout << x << " ";
    cout << "\n\n";

    cout << "Top Priority (getMax): " << getMax(pq) << "\n";

    cout << "Extracted Max: " << extractMax(pq) << "\n";

    cout << "After extraction: ";
    for (int x : pq) cout << x << " ";
    cout << "\n";

    increaseKey(pq, 2, 60);  // raise priority
    cout << "After increasing key at index 2 to 60: ";
    for (int x : pq) cout << x << " ";
    cout << "\n";

    return 0;
}

/* ==============================================================
   🧾 PRIORITY QUEUE OPERATIONS TABLE (Using Max Heap)
   ==============================================================
   | Operation        | Meaning                          | Heap Equivalent         | Time Complexity |
   |------------------|----------------------------------|-------------------------|-----------------|
   | insert(x)        | Add element with priority        | Add & bubble up         | O(log n)        |
   | getMax()         | View highest priority element    | Return root             | O(1)            |
   | extractMax()     | Remove highest priority element  | Delete root + heapify   | O(log n)        |
   | increaseKey(i,x) | Raise priority of an element     | Update + bubble up      | O(log n)        |
   ==============================================================
   ✅ Summary:
      - Heap = efficient way to implement priority queues
      - Always maintains order without full sorting
      - Used in schedulers, Dijkstra, job systems, etc.
   ============================================================== */
