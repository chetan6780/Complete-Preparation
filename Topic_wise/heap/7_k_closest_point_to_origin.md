# K closest point to origin.

Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

### Algorithm

1. Create max heap of pair of int and pair of int.
2. Treaverse all elements
   - push spuare of points , points itself.
   - if heap size is greater than k pop it.
3. print points remaining in heap.

### Code

```cpp

void k_closest_to_origin(int arr[][2], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});

        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    while (maxHeap.size() > 0)
    {
        pair<int, int> p = maxHeap.top().second;
        cout << p.first << " " << p.second << ";";
        maxHeap.pop();
    }
}
```
