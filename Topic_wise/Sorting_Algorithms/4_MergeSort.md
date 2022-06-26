# Merge Sort

-   **It is a divide and conquer algorithm.**
-   Divide the array into two halves, recursively sort the two halves and then merge the two sorted halves.
-   If array becomes empty or has only one element, then it is already sorted.
-   Recurrence relation for time complexity: **T(n) = 2T(n/2) + θ(n)**
-   **TC: O(n log n)**
-   **SC: O(n)**

### Code

```cpp
void merge(vector<int>& a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++) {
        left[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
    // delete left, right;
    // left.clear();
    // right.clear();
}

void mergeSort(vector<int>& a, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}
```

### Analysis

-   **Algorithmic Paradigm:** Divide and Conquer
-   **Is In-place Algorithm:** No
-   **Is Stable:** Yes

### Uses/Applications:

-   Sorting 2 linked list in O(n log n) time.
-   Inversion count problem.
-   External sorting.

### Drawbacks

-   Slower for smaller task compared to other sorting algorithms.
-   Requires additional memory.
-   Goes through the whole process even of array is sorted.

### Iterative Merge Sort

-   merge function remains same.
-   Read [full article](https://www.geeksforgeeks.org/iterative-merge-sort/) on GFG.
-   Time and space **complexity is same** as recursive solution but it does **not uses recursive stack**.

### Code

```cpp
void mergeSortIterative(vector<int>& a, int n)
{
    int currSize, left, right, mid;
    for (currSize = 1; currSize < n; currSize = 2 * currSize) {
        for (left = 0; left < n; left += 2 * currSize) {
            mid = min(left + currSize - 1, n - 1);
            right = min(left + 2 * currSize - 1, n - 1);

            merge(a, left, mid, right);
        }
    }
}
```

### Reference

-   [GFG - Merge sort](https://www.geeksforgeeks.org/merge-sort/)
