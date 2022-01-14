# Code Help DSA - Recursion

### 1. n'th fibonacci number

```cpp
int fibo(int n)
{
    if (n <= 1)
        return n;

    return fibo(n - 1) + fibo(n - 2);
}
```

### 2. is array sorted (OK)

```cpp
bool isSorted(int* arr, int size)
{
    // base case
    if (size == 0 || size == 1) {
        return true;
    }
    // Checking sorted condition
    if (arr[0] > arr[1])
        return false;

    // remaining part
    bool remainingPart = isSorted(arr + 1, size - 1);
    return remainingPart;
}
```

### 3. sum array - HW solved (OK)

```cpp
int sumArr(int* arr, int size)
{
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];

    return arr[0] + sumArr(arr + 1, size - 1);
}
```

---

### 4. Linear search (OK)

```cpp
bool linearSearch(int* arr, int size, int key)
{
    if (size == 0)
        return false;
    if (arr[0] == key)
        return true;

    return linearSearch(arr + 1, size - 1, key);
}
```

### 5. Binary search (OK)

```cpp
bool binarySearch(int* arr, int key, int left, int right)
{
    if (left > right)
        return false;

    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
        return true;

    if (arr[mid] > key) {
        return binarySearch(arr, key, left, mid - 1);
    } else {
        return binarySearch(arr, key, mid + 1, right);
    }
}
```

---

### 6. Reverse a string (OK)

```cpp
void reverseStr(string& s, int left, int right)
{
    if (left > right)
        return;

    swap(s[left], s[right]);
    return reverseStr(s, left + 1, right - 1);
}
```

// We can also do like, left=i, right=n-i-1;

### 7. check palindrome (OK)

```cpp
bool isPalindrome(string s, int left, int right)
{
    if (left > right)
        return true;

    if (s[left] != s[right])
        return false;

    return isPalindrome(s, left + 1, right - 1);
}
```

// We can also do like, left=i, right=n-i-1;

---

### 8. power of the number (OK)

```cpp
int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    return a * power(a, b - 1);
}
```

### 9. power of the number (optimized) (OK)

```cpp
int powerOpt(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int ans = powerOpt(a, b / 2);
    if (b & 1) {
        return a * ans * ans;
    } else {
        return ans * ans;
    }
}
```

---

### 9. bubble sort (OK)

```cpp
void bubbleSort(int* arr, int n)
{
    if (n == 0 || n == 1)
        return;

    // solved one question - largest element to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSort(arr, n - 1);
}
```

// Selection sort - i'th smallest element at i'th position
// Bubble sort - i'th largest element at its right position
// Selection sort - smallest element to its right position

### 10. Merge sort (OK)

```cpp
void merge(int* arr, int left, int right)
{
    int mid = left + (right - left) / 2;

    int len1 = mid - left + 1;
    int len2 = right - mid;

    // Create 2 new arrays
    int* first = new int[len1];
    int* second = new int[len2];

    // copy values
    int k = left;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    // merge values
    int ind1 = 0, ind2 = 0;
    int mainArrIndex = left;

    while (ind1 < len1 && ind2 < len2) {
        if (first[ind1] < second[ind2]) {
            arr[mainArrIndex++] = first[ind1++];
        } else {
            arr[mainArrIndex++] = second[ind2++];
        }
    }
    while (ind1 < len1) { // Remaining values in first array
        arr[mainArrIndex++] = first[ind1++];
    }
    while (ind2 < len2) { // Remaining values in second array
        arr[mainArrIndex++] = second[ind2++];
    }

    // Delete to prevent memory leaks
    delete[] first;
    delete[] second;
}

void mergeSort(int* arr, int left, int right)
{
    if (left >= right) // condition for greater and equal (IMP)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid); // Sort left part
    mergeSort(arr, mid + 1, right); // Sort right part

    merge(arr, left, right); // Merge 2 sorted arrays
}
```

### 11. Quicksort (OK)

