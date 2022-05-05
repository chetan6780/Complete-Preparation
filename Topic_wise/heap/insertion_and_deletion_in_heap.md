# Insertion and deletion in Heap

### Deletion at root

### Algorithm

1. To delete root of heap we perform following operations.
    - Get the last element.
    - Replace root with last element.
    - Decrease size of heap by 1.
    - heapify the root node.
2. Heapify function.
    - Initialize largest as root.
    - left = 2\*i + 1
    - right = 2\*i + 2
    - If left child is larger than root, then set it as larger.
    - If right child is larger than largest so far, then set it as larger.
    - If largest is not root.
    - swap root and largest node.
    - Recursively heapify the affected sub-tree.

### Code

```cpp
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int &n)
{
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    heapify(arr, n, 0);
}
```

---

### Insertion in heap

### Algorithm

1. Heapify function.
    - Find parent (i - 1) / 2 .
    - For Max-Heap If current node is greater than its parent Swap both of them and call heapify again for the parent.
    - Recursively heapify the parent node.
2. insert node Function.
    - Insert the element at end of Heap.
    - Increase the size of Heap by 1.
    - Heapify the new node following a Bottom-up approach.

### Code

```cpp

// Bottom-up approach
void heapify(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (parent >= 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            heapify(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int &n, int Key)
{
    arr[n] = Key;
    n = n + 1;
    heapify(arr, n, n - 1);
}
```
