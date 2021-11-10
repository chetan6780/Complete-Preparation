# Number of times array rotated

-   if we observe, the number of times array rotated is equal to the **first occurrence** of minimum element.
-   Now the problem becomes, find the first occurrence of minimum element.
-   Our first task is to find minimum element.
    -   if the mid element is less than previous element and greater than next element then it is min element.
    -   `prev = (mid - 1 + n) % n`, it handles the case of `mid = 0`.
    -   `next = (mid + 1) % n`, it handles the case of `mid = n-1`.
-   next task is to find where to go.
-   We can observe that each time the minimum element occurs in the unsorted subarray.
-   if left element is less than mid element then left subarray is sorted array and we move `l to mid+1`.
-   else if mid element is less than right element then right subarray is sorted array and we move `r to mid-1`.

### Code

```cpp
int numberOfTimesRotated(vector<int> &a)
{
    int n = a.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int prev = (mid - 1 + n) % n; // if mid is in the start, so we add n and do mod n
        int next = (mid + 1) % n;     // if mid is in the end, so we do mod n
        if (a[next] > a[mid] && a[prev] < a[mid]) {
            return mid;
        }
        if (a[l] <= a[mid]) {
            l = mid + 1;
        } else if (a[mid] <= a[r]) {
            r = mid - 1;
        }
    }
    return 0;
}
```
