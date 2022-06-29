# Selection Sort Algorithm

### Selection Sort

-   **Select the minimum element and place it at the beginning of the array.**
-   It maintains two subarrays: sorted and remaining unsorted.
-   In every iteration, minimum element from unsorted array is moved to the sorted array.
-   **TC: O(N^2)**
-   **SC: O(1)**

### Code

```cpp
void selectionSort(vector<int>& a, int n)
{
    for (int i = 0; i < n - 1; i++) { // till n-1
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}
```

### Stable Selection Sort

-   **A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in sorted output as they appear in the input array to be sorted.**
-   Selection sort finds the minimum element and swaps it with its correct position in sorted subarray, this is what it **makes it unstable**.
-   Swapping might impact in pushing a key to a position greater than the key which are equal keys. which makes them out of desired order.

### Code

```cpp
void stableSelectionSort(vector<int>& v, int n)
{
    int minIndex = 0;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        // Move minimum element at current i
        int minElement = v[minIndex];
        while (minIndex > i) {
            v[minIndex] = v[minIndex - 1];
            minIndex--;
        }
        v[minIndex] = minElement;
    }
}
```

### Analysis

-   **Is Stable**: Default implementation of selection sort is not stable.
-   **Is In-place Algorithm:** Yes

### References

-   [GFG - Selection Sort Algorithm](https://www.geeksforgeeks.org/selection-sort/)
