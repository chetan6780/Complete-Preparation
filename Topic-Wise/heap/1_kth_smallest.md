# K'th Smallest element

### Algorithm

1. create a max heap (HINT: Because we have k and smallest in problem.)
2. traverse all elements of the array.
    - push the element in max heap.
    - if size is greater than k pop the top element of max heap.
3. return the top of max heap.

### Code

```cpp

int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);

        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
}
```

### Complexity

Time Complexity: **O(N\*logK)**
