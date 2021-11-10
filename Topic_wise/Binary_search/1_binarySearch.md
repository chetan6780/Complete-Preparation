# Binary Search

### Ascending sorted array - binary search

- If the array is sorted in ascending order then we do simple binary search.
- take l pointer to the first element of the array and r pointer to the last element of array.
- while l is less than or equal to r we do
  - calculate mid = l+(r - l)/2 , here we don't take (l+r)/2 because if the value of l and r is huge then it will result in overflow.
  - if the mid element is the key return it.
  - else if the mid element is less than key we move l to mid+1.
  - else we move r to mid-1.
- if element is not present in the array then return -1.

### Code

```cpp
int binarySearch(vector<int> &a, int key)
{
    int l = 0, r = a.size() - 1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (a[mid] == key){
            return mid;
        }
        else if (a[mid] < key){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}
```

---

### Descending sorted array - binary search

- Here we just need to interchange conditions of moving pointers.

### Code

```cpp
int binarySearchDes(vector<int> &a, int key)
{
    int l = 0, r = a.size() - 1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (a[mid] == key){
            return mid;
        }
        else if (a[mid] < key){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}
```

---

### Not known sorted array - binary search

- Now we know that the array is sorted, but we don't know the ordering.
- In this case we compare the first and last elements of the array.
- if they are in descending order , then use descending wala binary search else use ascending wala binary.

### Code

```cpp
int binarySearchNK(vector<int> &a, int key)
{
    bool desc = (a[0] > a[a.size() - 1]); // check
    int l = 0, r = a.size() - 1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (a[mid] == key){
            return mid;
        }
        else if (a[mid] < key){
            (desc == true) ? r = mid - 1: l = mid + 1;
        }
        else{
            (desc == true) ? l = mid + 1 : r = mid - 1;
        }
    }
    return -1;
}
```
