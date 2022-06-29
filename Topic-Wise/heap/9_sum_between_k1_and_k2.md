# Sum of Elements between k1 smallest and k2 smallest numbers

### Prerequisites:

-   [k'th smallest element](1_kth_smallest.md)
-   After above question code is self explanatory.

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

int sum_bet_k1_k2(int *arr, int n, int k1, int k2)
{
    // Get smallest for k1 and k2
    int first = kthSmallest(arr, n, k1);
    int second = kthSmallest(arr, n, k2);

    // get sum
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first && arr[i] < second)
            sum += arr[i];
    }
    return sum;
}
```
