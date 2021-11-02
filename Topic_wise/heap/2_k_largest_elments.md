# K'th Largest element

### Algorithm

1. create a min heap (HINT: Because we have k and largest in problem.)
2. traverse all elements of the array.
   - push the element in max heap.
   - if size is greater than k pop the top element of min heap.
3. print the top until heap is not empty.

### Code

```cpp

void k_largest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);

        if (minHeap.size() > k)
            minHeap.pop();
    }

    while (minHeap.size() > 0)
    {
        cout << minHeap.top() << ' ';
        minHeap.pop();
    }
}
```