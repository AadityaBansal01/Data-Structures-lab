#include <iostream>
using namespace std;

/* -----------------------------------------------------------
   🔹 MAX-HEAPIFY FUNCTION
   -----------------------------------------------------------
   → Fixes the heap property for a node i in array arr[]
   → Assumes: left and right subtrees are already heaps
   → Works by:
        1. Compare parent with its children
        2. Swap with the largest child if needed
        3. Recursively heapify the affected subtree
   ----------------------------------------------------------- */
void heapify(int arr[], int n, int i) {
    int largest = i;        // assume parent (i) is largest
    int left = 2*i + 1;     // left child index
    int right = 2*i + 2;    // right child index

    // if left child is larger than parent
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not parent → heap property violated
    if (largest != i) {
        swap(arr[i], arr[largest]);  // swap parent with larger child
        heapify(arr, n, largest);    // recursively fix the affected subtree
    }
}

/* -----------------------------------------------------------
   🔹 BUILD-MAX-HEAP FUNCTION
   -----------------------------------------------------------
   → Converts entire array into a valid max heap
   → Starts from last non-leaf node (n/2 - 1)
   → Calls heapify for each internal node in reverse level order
   → Time Complexity: O(n)
   ----------------------------------------------------------- */
void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

/* -----------------------------------------------------------
   🔹 HEAP SORT FUNCTION
   -----------------------------------------------------------
   → Steps:
        1. Build a max heap from the array
        2. Repeatedly swap the root (max) with the last element
        3. Reduce heap size by 1
        4. Call heapify to restore heap property
   → Overall Time Complexity: O(n log n)
   → Space Complexity: O(1)
   ----------------------------------------------------------- */
void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n); // Step 1: create initial heap

    // Step 2: extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move current max to end
        heapify(arr, i, 0);     // fix the heap property for reduced heap
    }
}

/* -----------------------------------------------------------
   🔹 MAIN FUNCTION
   -----------------------------------------------------------
   → Input: unsorted array
   → Output: sorted array using Heap Sort
   ----------------------------------------------------------- */
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/* -----------------------------------------------------------
   🧠 QUICK NOTES (perfect for slides or viva)
   -----------------------------------------------------------
   ✅ Heap Property:
        - Max Heap → parent ≥ children
        - Min Heap → parent ≤ children
   ✅ heapify() fixes one subtree  → O(log n)
   ✅ buildMaxHeap() fixes entire tree → O(n)
   ✅ heapSort() = build + n extractions → O(n log n)
   ✅ In-place, not stable, predictable performance
   ----------------------------------------------------------- */
