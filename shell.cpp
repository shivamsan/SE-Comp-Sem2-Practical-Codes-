#include <iostream>

using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int size) {
    // Start with a large gap and reduce it over iterations
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Perform insertion sort on elements gapped by 'gap'
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;

            // Shift elements of subarray arr[0..i-gap-1], arr[0..i-2*gap-1], ... by gap positions
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
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

    shellSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
