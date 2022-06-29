# Number of times array rotated

-   if we observe, the number of times array rotated is equal to the **first occurrence** of minimum element.
-   Now the problem becomes, find the first occurrence of minimum element.
-   Our first task is to find minimum element.
    -   if next is less than mid, then return mid+1
    -   if prev is greater than mid, then return mid
-   next task is to find where to go.
    -   if mid is greater than start, then `left = mid + 1`, else `right = mid - 1`
-   **NOTE: In Aditya verma video many testcases are not considered. like duplicates and array is not rotated.The below is leetcode solution**

### Code-1

```cpp
int numberOfTimesRotated(vector<int>& a)
{
    int n = a.size();
    int left = 0, right = n - 1;
    if (n == 0 || a[right] > a[left]) return 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // if next is less than mid, then return mid+1
        if (a[mid + 1] < a[mid]) { return mid + 1; }
        // if prev is greater than mid, then return mid
        if (a[mid - 1] > a[mid]) { return mid; }
        // if mid is greater than start, then left = mid + 1, else right = mid - 1
        (a[mid] > a[0]) ? left = mid + 1 : right = mid - 1;
    }
    return -1;
}
```

### Code-2

```cpp
int numberOfTimesRotated(vector<int>& a)
{
    int n = a.size();
    int left = 0, right = n - 1;
    while (left < right) { // note this
        int mid = left + (right - left) / 2;
        if (a[mid] >= a[right])
            left = mid + 1;
        else
            right = mid; //note this
    }
    return left; // note this
}
```
