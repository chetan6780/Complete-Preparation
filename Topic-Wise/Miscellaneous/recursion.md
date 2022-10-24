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

```cpp

int partition(int* arr, int left, int right)
{
    int pivot = arr[left];

    int cnt = 0;
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    int pivotIndex = left + cnt;
    swap(arr[pivotIndex], arr[left]);

    int i = left, j = right;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int* arr, int left, int right)
{
    if (left >= right)
        return;

    int p = partition(arr, left, right);

    quickSort(arr, left, p - 1);
    quickSort(arr, p + 1, right);
}
```

---

### 12. Subsets (OK)

```cpp
void subsets_helper(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans)
{
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // exclude
    subsets_helper(nums, output, index + 1, ans);

    // include
    output.push_back(nums[index]);
    subsets_helper(nums, output, index + 1, ans);
    output.pop_back(); // this line is for pass by reference output only // for pass by value it is not required
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> res;
    int index = 0;
    subsets_helper(nums, res, index, ans);
    return ans;
}
```

Another helper

```cpp
void subsets_helper(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans)
{
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // include
    output.push_back(nums[index]);
    subsets_helper(nums, output, index + 1, ans);

    // exclude
    output.pop_back();
    subsets_helper(nums, output, index + 1, ans);
}
```

### Subsequences (OK)

```cpp

void subsequences_helper(string s, string output, int index, vector<string>& ans)
{
    if (index >= s.size()) {
        if(output.size() > 0) // to avoid empty string
            ans.push_back(output);
        return;
    }

    // exclude
    subsequences_helper(s, output, index + 1, ans);

    // include
    output.push_back(s[index]);
    subsequences_helper(s, output, index + 1, ans);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    subsequences_helper(str, output, index, ans);
    return ans;
}
```

Another helper function

```cpp
void subsequences_helper(string& s, string& output, int index, vector<string>& ans)
{
    if (index >= s.size()) {
        if (output.size() > 0) // to avoid empty string
            ans.push_back(output);
        return;
    }

    // include
    output.push_back(s[index]);
    subsequences_helper(s, output, index + 1, ans);

    // exclude
    output.pop_back();
    subsequences_helper(s, output, index + 1, ans);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    subsequences_helper(str, output, index, ans);
    return ans;
}
```

---

### Letter Combinations of a Phone Number

-   Asked in multiple mnc companies

```cpp
void letterCombinations_helper(string digits, string& output, int index, vector<string>& map, vector<string>& ans)
{
    if (index >= digits.size()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = map[number];

    for (int i = 0; i < value.size(); i++) {
        output.push_back(value[i]);
        letterCombinations_helper(digits, output, index + 1, map, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0)
        return {};
    vector<string> ans;
    int index = 0;
    string output = "";
    vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    letterCombinations_helper(digits, output, index, map, ans);
    return ans;
}
```

---

### Permutation of the string

```cpp
void permute_helper(vector<int>& nums, int index, vector<vector<int>>& ans)
{
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++) { // give chance to next characters
        swap(nums[index], nums[j]);
        permute_helper(nums, index + 1, ans);
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans;
    int index = 0;
    permute_helper(nums, index, ans);
    return ans;
}
```

---

### Rat in maze

```cpp

bool isSafe(int x, int y, int n, vector<vector<bool>>& vis, vector<vector<int>>& m)
{
    if (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && vis[x][y] == false)
        return true;
    return false;
}

void findPath_helper(vector<vector<int>>& m, int n, int x, int y, vector<vector<bool>>& vis, string path, vector<string>& ans)
{
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = true;

    // Down
    int newX = x + 1;
    int newY = y;
    if (isSafe(newX, newY, n, vis, m)) {
        path.push_back('D');
        findPath_helper(m, n, newX, newY, vis, path, ans);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, n, vis, m)) {
        path.push_back('R');
        findPath_helper(m, n, newX, newY, vis, path, ans);
        path.pop_back();
    }

    // Up
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, n, vis, m)) {
        path.push_back('U');
        findPath_helper(m, n, newX, newY, vis, path, ans);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, n, vis, m)) {
        path.push_back('L');
        findPath_helper(m, n, newX, newY, vis, path, ans);
        path.pop_back();
    }

    vis[x][y] = false;

    return;
}

vector<string> findPath(vector<vector<int>>& m, int n)
{
    vector<string> ans = {};

    // If first cell is 0
    if (m[0][0] == 0)
        return ans;

    // Src locations
    int srcX = 0;
    int srcY = 0;

    // Visited vector
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    string path = "";
    findPath_helper(m, n, srcX, srcY, visited, path, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
```

---
