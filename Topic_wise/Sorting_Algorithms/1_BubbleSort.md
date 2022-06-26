# Bubble Sort Algorithm

### Bubble Sort

-   Swap the adjacent elements if they are in wrong order.
-   Not Suitable for large data sets.
-   **TC: O(n^2)**
-   **SC: O(1)**

### Code

```cpp
void bubbleSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++) { // till n-1
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) { // till n-i-1
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
```

### Optimization

-   Even if the array is already sorted, the algorithm still runs O(n^2) time.
-   To avoid this, we can use the `flag` to check if the array is already sorted.

### Code

```cpp
void bubbleSort(vector<int>& v)
{
    int n = v.size();
    bool swapped = false;
    for (int i = 0; i < n; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
```

### Analysis

-   **Worst Case**: When the array is already sorted in descending order.**TC: O(N^2)**
-   **Best Case**: When the array is already sorted in ascending order.**TC: O(N)**
-   **Is Stable**: Yes.
-   Check if array is already sorted to avoid O(N^2) time,then it will take linear time. This is the **Boundary case** for bubble sort.

### Uses:

-   To introduce the concept of sorting. (Due to its simplicity.)
-   Detect small errors((like a swap of just two elements) in the data.It fixes the problem in 2n time.

### Reference

-   [GFG - Bubble Sort Algorithm](https://www.geeksforgeeks.org/bubble-sort/)

---

### **Recursive Bubble Sort**

-   Recursive Bubble Sort has **no performance/implementation advantages**, but can be a good question to **check one’s understanding** of Bubble Sort and recursion.
-   **TC: O(n^2)**
-   **SC: O(n)**

```cpp
void bubbleSort(vector<int>& v, int n)
{
    // Recursive bubble sort
    if (n == 1)
        return;
    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            swap(v[i], v[i + 1]);
            swapped = true;
        }
    }
    if (!swapped)
        return;
    bubbleSort(v, n - 1);
}
```
