# Top k frequent elements

### Algorithm

1. create min heap with pair.
2. get the frequencies.
   - push the (freq,value) pair in heap.
   - if size is greater than k pop the top.
3. while heap is not empty, print second of each element.

### Code

```cpp

void get_k_frequent(int *arr, int n, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        minHeap.push(make_pair(it->second, it->first));

        if (minHeap.size() > k)
            minHeap.pop();
    }
    while (minHeap.size() > 0)
    {
        cout << minHeap.top().second << ' ';
        minHeap.pop();
    }
}
```
