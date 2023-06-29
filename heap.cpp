#include <iostream>

using namespace std;

// Function to heapify a subtree rooted at 'root' index
void heapify(int arr[], int size, int root) {
    int largest = root;    // Initialize largest as root
    int left = 2 * root + 1;    // Left child index
    int right = 2 * root + 2;   // Right child index

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int size) {
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(arr, size, i);

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; --i) {
        swap(arr[0], arr[i]);

        // Heapify root element to get the maximum element at the root again
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
