# [230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

### Inorder traversal

-   Binary search tree in inorder traversal gives sorted values.
-   So we can find kth smallest from the list.
-   **TC: O(N)**
-   **SC: O(N)**, To store inorder traversal.

### Code

```cpp
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& list)
    {
        if (!root) return;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> list;
        inorder(root, list);
        return list[k - 1];
    }
};
```

### Get kth while traversing.

-   We don't need to traverse whole tree, instead we can just traverse until we find kth smallest element.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
private:
    int ans = 0;
    void inorder(TreeNode* root, int& k)
    {
        if (!root) return;
        inorder(root->left, k);
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        inorder(root, k);
        return ans;
    }
};
```

### Above method in iterative way.

### Code

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> st;
        while (1) {
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top(), st.pop();
            k--;
            if (k == 0)
                return root->val;
            root = root->right;
        }
        return 0;
    }
};
```
