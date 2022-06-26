# Insertion Sort Algorithm

### Insertion Sort

-   **Insert the chosen element into the sorted array at its correct position.**
-   Array is virtually split into 2 subarrays: sorted and unsorted.
-   Values form unsorted array are inserted into sorted array one by one.
-   **TC: O(n^2)**
-   **SC: O(1)**

### Code

```cpp
void insertionSort(vector<int>& a, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        // move key to its correct position in sorted array
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
```

### Binary Insertion Sort

-   We can find the location to insert the element with binary search.
-   In normal insertion takes **O(i)** at ith iteration, now we can do it in **O(log i)** time.
-   Final time complexity is still **O(n^2)**.

### Code

```cpp

int binarySearch(vector<int>& a, int key, int lo, int hi)
{
    if (lo >= hi)
        return (key > a[lo]) ? lo + 1 : lo;

    int mid = (lo + hi) / 2;

    if (key == a[mid]) return mid + 1;

    if (key > a[mid])
        return binarySearch(a, key, mid + 1, hi);
    return binarySearch(a, key, lo, mid - 1);
}

void binaryInsertionSort(vector<int>& a, int n)
{
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        int loc = binarySearch(a, key, 0, j);
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
```

### Analysis

-   **Is Sorted**: Yes
-   **Boundary Cases**: max time - when array is already sorted in reverse order, min time - when array is already sorted in ascending order
-   **Algorithmic Paradigm**: Follows incremental approach

### Uses

-   Number of elements are small.
-   Big array is almost sorted

### Reference

-   [GFG - Insertion Sort Algorithm](https://www.geeksforgeeks.org/insertion-sort/)

---

### Recursive Insertion Sort

-   Recursive Insertion Sort has **no performance/implementation advantages**, but can be a good question to **check one’s understanding** of Insertion Sort and recursion.

### Code

```cpp
void insertionSortRec(vector<int>& a, int n)
{
    if (n == 1) return;

    // sort first n-1 elements
    insertionSortRec(a, n - 1);

    // insert last element to its correct position
    int last = a[n - 1];
    int j = n - 2;
    while (j >= 0 && a[j] > last) {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = last;
}
```
