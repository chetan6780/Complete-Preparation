# Sort k sorted array

### Algorithm

1. create a min heap (HINT: Because we have k and largest in problem) and vector to store answer.
2. traverse all elements of the array.
    - push the element in min heap.
    - if size is greater than k pop the top element of min heap.
    - push the top in the vector.
    - pop the top element element.
3. until heap is not empty push the top element in vector.

### Code

```cpp

vector<int> k_sorted_array(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            v.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while (minHeap.size() > 0)
    {
        v.push_back(minHeap.top());
        minHeap.pop();
    }
    return v;
}
```
