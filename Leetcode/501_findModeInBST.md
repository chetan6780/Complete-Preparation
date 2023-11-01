# [501. Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/) 🌟

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

-   The left subtree of a node contains only nodes with keys less than or equal to the node's key.
-   The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
-   Both the left and right subtrees must also be binary search trees.

**Follow up:** Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count). 🌟🌟

### Hash map with DFS

-   Traverse all the tree and store frequency of each node in a hash map.
-   Get the highest frequency and return vector with all elements with that frequency.
-   **TC: O(N^2)**
-   **SC: O(N)**

### Code

```cpp

class Solution {
private:
    void dfs(TreeNode* root, unordered_map<int, int>& mp, int& max) {
        if (root == nullptr) {
            return;
        }
        mp[root->val]++;
        if (mp[root->val] > max) {
            max = mp[root->val];
        }
        dfs(root->left, mp, max);
        dfs(root->right, mp, max);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> res;
        int max = 0;
        dfs(root, mp, max);
        for(auto& [k, v] : mp) {
            if (v == max) {
                res.push_back(k);
            }
        }
        return res;
    }
};
```

### Iterative DFS

-   Same as above but iterative DFS.

### Code

```cpp
class Solution {
public:
    vector<int> findMode(TreeNode* root)
    {
        unordered_map<int, int> mp;
        // iterative dfs
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            mp[node->val]++;
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        vector<int> res;
        int mx = 0;

        for (auto& [k, v] : mp) {
            mx = max(mx, v);
        }

        for (auto& [k, v] : mp) {
            if (v == mx) res.push_back(k);
        }

        return res;
    }
};
```

### Without extra space(without Hashmap)

-   Just little modification in inorder traversal.
-   Keep track of previous node, current frequency and max frequency.
-   Every time we encounter a new node, check if it is equal to previous node, if yes, increment current frequency, else reset it to 1.
-   If current frequency is equal to max frequency, add it to result vector, else if current frequency is greater than max frequency, clear the result vector and add current node to it and update max frequency.
-   **TC: O(N)**
-   **SC: O(1)**, if we don't consider the result vector and recursion stack.

### Code

```cpp

class Solution {
    void inorder(TreeNode* root, int& prev, int& currFreq, int& maxFreq, vector<int>& res)
    {
        if (!root) return;
        inorder(root->left, prev, currFreq, maxFreq, res);
        if (prev == root->val) {
            currFreq++;
        } else {
            currFreq = 1;
        }
        if (currFreq == maxFreq) {
            res.push_back(root->val);
        } else if (currFreq > maxFreq) {
            res.clear();
            res.push_back(root->val);
            maxFreq = currFreq;
        }
        prev = root->val;
        inorder(root->right, prev, currFreq, maxFreq, res);
    }

public:
    vector<int> findMode(TreeNode* root)
    {
        vector<int> res;
        int maxFreq = 0, currFreq = 0, prev = INT_MIN;
        inorder(root, prev, currFreq, maxFreq, res);
        return res;
    }
};
```

### Morris Traversal

- **TC: O(N)**
- **SC: O(1)**

Coming Soon ...

TODO: solve using morris traversal.
