# k Closest elements

### Algorithm

1. create a max heap of pair (index,element) and vector to store answer.
2. traverse all elements of the array.
   - push the pair in max heap.
   - if size is greater than k pop the top element of max heap.
3. until heap is not empty push the second element of top in vector.

### Code

```cpp

vector<int> k_closest(int *arr, int n, int k, int x)
{
    priority_queue<pair<int, int>> maxHeap;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push({abs(arr[i] - x), arr[i]});

        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    while (maxHeap.size() > 0)
    {
        v.push_back(maxHeap.top().second);
    }
    return v;
}
```