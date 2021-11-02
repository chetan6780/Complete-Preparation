# Connect ropes to minimize cost

### Algorithm

1. Initialalize cost and minHeap with default values.
2. while size of min heap is greater than or equal to 2, get top 2 elements and add them in the cost
   - push first + second in minHeap
3. return cost

### Code

```cpp

int connect_ropes(int arr[], int n)
{
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap(arr, arr + n);

    while (minHeap.size() >= 2)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        cost = cost + first + second;
        minHeap.push(first + second);
    }
    return cost;
}
```
