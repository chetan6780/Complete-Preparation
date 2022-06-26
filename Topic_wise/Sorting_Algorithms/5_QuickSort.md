# Quick Sort

-   **It is a divide and conquer algorithm.**
-   **GFG has one of the very detailed article on Quick Sort. It is highly recommended to read it.** See reference below.
-   The key process in quickSort is **partition()**.
-   It picks an element as pivot and partitions the given array around the picked pivot.
-   There are many different versions of quickSort that pick pivot in different ways.
    -   Always pick first element as pivot.
    -   Always pick last element as pivot (implemented below).
    -   Pick a random element as pivot.
    -   Pick median as pivot.
-   All elements less that pivot are moved to left of pivot and all elements greater than pivot are moved to right of pivot.
-   After that quickSort left and right subarrays.

### Code

```cpp

int partition(vector<int>& arr, int l, int r)
{
    int pivot = arr[r]; // last element as pivot
    int i = l - 1; // index of smaller element
    for (int j = l; j < r; j++) {
        // if current element is smaller than the pivot
        if (arr[j] <= pivot) {
            swap(arr[i + 1], arr[j]);
            i++; // increment index of smaller element
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int r)
{
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
```

### First element as pivot

```cpp
int partition(vector<int>& arr, int l, int r)
{
    int pivot = arr[l]; // first element as pivot
    int i = l, j = r;

    while (i < j) {
        while (arr[i] <= pivot && i < r)
            i++;
        while (arr[j] > pivot && j > l)
            j--;
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}
```

### Analysis

-   **Worst Case**: Partition process always picks greatest or smallest element as pivot.**O(N^2)**
-   **Best Case**: Partition process always picks middle element as pivot.(middle value element). **O(NlogN)**
-   **Average Case**: **O(NlogN)**
-   **Is Stable**: Default implementation is Not stable, But can be made stable by considering indexes as comparison parameter.
-   **Is in-place**: Yes.

### Important note

-   Although the worst case time complexity of QuickSort is O(n^2) which is more than many other sorting algorithms like Merge Sort and Heap Sort, **QuickSort is faster in practice**, because its inner loop can be efficiently implemented on most architectures, and in most real-world data.
-   QuickSort can be implemented in different ways by changing the choice of pivot, so that the **worst case rarely occurs** for a given type of data.
-   However, merge sort is generally considered better when data is huge and stored in external storage.

### Why Quick Sort is preferred over MergeSort for sorting Arrays ?

-   Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm. Comparing average complexity we find that both type of sorts have O(NlogN) average complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.
-   Most practical implementations of Quick Sort use randomized version. The randomized version has expected time complexity of O(nLogn). The worst case is possible in randomized version also, but worst case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.
-   Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when used for arrays.
-   Quick Sort is also tail recursive, therefore tail call optimizations is done.

### Why MergeSort is preferred over QuickSort for Linked Lists ?

-   In case of linked lists the case is different mainly due to difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory. Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time. Therefore merge operation of merge sort can be implemented without extra space for linked lists.
-   In arrays, we can do random access as elements are continuous in memory. Let us say we have an integer (4-byte) array A and let the address of A[0] be x then to access A[i], we can directly access the memory at (x + i\*4). Unlike arrays, we can not do random access in linked list. Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort. Merge sort accesses data sequentially and the need of random access is low.

### How to optimize QuickSort so that it takes O(Log n) extra space in worst case?

-   [QuickSort Tail Call Optimization (Reducing worst case space to Log n )](https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/)

### Iterative Quick Sort

-   Read [this article](https://www.geeksforgeeks.org/iterative-quick-sort/).

### Reference

-   [GFG - Quick Sort](https://www.geeksforgeeks.org/quick-sort/)
