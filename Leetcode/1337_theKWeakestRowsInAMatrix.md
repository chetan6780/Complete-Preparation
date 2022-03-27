# [1337. The K Weakest Rows in a Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/) 🌟

You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

### Multimap

-   We can store pair of `{no.of soldiers, row index}` in a multimap.
-   first k elements in multimap will be k weakest rows.

### Code

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        multimap<int, int> mp;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int ones = count(mat[i].begin(), mat[i].end(), 1); // count 1's in row i
            mp.insert(make_pair(ones, i));
        }

        vector<int> res;
        for (auto x : mp) {
            res.push_back(x.second);
            k--;
            if (k == 0)
                break;
        }
        return res;
    }
};
```

### priority_queue

-   This approach is same as previous multimap approach, we just used priority queue instead of multimap.

### Code

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int ones = count(mat[i].begin(), mat[i].end(), 1); // linear
            pq.push({ones, i});
        }
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```

### priority_queue + binary search

-   we can use binary search to find how many soldiers are there in i'th row.
-   rest approaches is same as previous approaches.

### Code

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            int ones = count(mat[i].begin(), mat[i].end(), 1); // linear search
            pq.push({ones, i});
        }
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```

### vertical scanning

-   We will scan the matrix vertically.
-   If we encounter 0 and we didn't visited that row before, we will add that row index in result and in set. Decrease the k and if k is 0 return result vector.
-   If any row contains no 0's then we will add them in there respective order in matrix.

### Code

```cpp

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;
        set<int> st;
        for (int c = 0; c < m; c++) {
            for (int r = 0; r < n; r++) {
                if (mat[r][c] == 0 && st.count(r) == 0) {
                    st.insert(r);
                    ans.push_back(r);
                    --k;
                    if (k == 0)
                        return ans;
                }
            }
        }
        // if vector does not contain 0 last element will be 1;
        for (int i = 0; i < n; i++) {
            if (mat[i][m - 1] == 1) {
                ans.push_back(i);
                --k;
                if (k == 0)
                    break;
            }
        }
        return ans;
    }
};
```
