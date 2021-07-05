# Maximum of all subarrays of size k 

### Statement

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

### Algorithm

1. Create deque and answer vector.
2. Process first k (or first window) elements of array
    - remove the previous smaller for every element
       - Remove from rear
    - Add new element at rear of queue
3. Process rest of the elements, i.e., from arr[k] to arr[n-1]
    - The element at the front of the queue is the largest element
    - Remove the elements which are out of this window
       - Remove from front of queue
    - Remove all elements smaller than the currently being added element (remove useless elements)
    - Add current element at the rear of Qi
4. push the maximum element of last window
5. Return answer vector.



### Code

```cpp

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> Qi(k);
    vector<int> ans;

    // Process first k (or first window) elements of array
    int i;
    for (i = 0; i < k; ++i)
    {

        // remove the previous smaller for every element
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

            // Remove from rear
            Qi.pop_back();

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {

        // The element at the front of the queue is the largest element
        ans.push_back(arr[Qi.front()]);

        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)

            // Remove from front of queue
            Qi.pop_front();

        // Remove all elements smaller than the currently being added element (remove useless elements)
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        // Add current element at the rear of Qi
        Qi.push_back(i);
    }

    // push the maximum element of last window
    ans.push_back(arr[Qi.front()]);

    return ans;
}

```

### Complexity: O(n)

### References

- GFG : [link](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/)
