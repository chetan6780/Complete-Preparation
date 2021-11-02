# Frequency sort

### Prerequisite
- This problem is based on [top k frequent element](5_top_k_frequent_element.md).
- Code is self explanatory.

### Code
```cpp
void frequentSort(int *arr, int n, int k)
{
    priority_queue<pair<int, int>> maxHeap;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto it = mp.begin(); it != mp.end(); it++)
        maxHeap.push({it->second, it->first});

    while (maxHeap.size() > 0)
    {
        int freq = maxHeap.top().first;
        int elem = maxHeap.top().second;
        while (freq--)
            cout << elem << ' ';

        maxHeap.pop();
    }
}
```