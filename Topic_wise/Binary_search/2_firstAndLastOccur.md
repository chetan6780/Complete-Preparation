# First and last occurrence

### First Occurrence

- In the binary search algorithm we just do small changes, instead of returning the index (if found) we will store it in the result variable/
- then we move right to mid-1;
- finally return the result.

### Code

```cpp
int firstOccurrence(vector<int> &a,int num){
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] == num){
            res = mid;   // store result
            r = mid - 1; // right = mid - 1
        }else if(num<a[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return res;
}
```

---

### Last Occurrence

- In the binary search algorithm we just do small changes, instead of returning the index (if found) we will store it in the result variable/
- then we move left to mid+1;
- finally return the result.

### Code

```cpp
int lastOccurrence(vector<int> &a,int num){
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] == num){
            res = mid;    // store result
            l = mid + 1;  // left = mid + 1
        }else if(num<a[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return res;
}
```

---

### Count the frequency of number

- Using the first and last occurrences we can easily calculate the frequency of number.

### Code

```cpp
int frequency(vector<int> &a,int num){
    return lastOccurrence(a, num) - firstOccurrence(a, num) + 1;
}
```
