# [530. Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

### Inorder

-   Get the inorder of BST which is sorted.
-   We can find min diff by `next-prev` in inorder vector.

### Code

```cpp
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

public:
    int getMinimumDifference(TreeNode* root)
    {
        int mindiff = INT_MAX;
        vector<int> v;
        inorder(root, v);
        int n = v.size();
        for (int i = 0; i < n - 1; i++)
            mindiff = min(mindiff, v[i + 1] - v[i]);
        return mindiff;
    }
};
```

### Without Extra O(N) space in order

-   We can maintain prev value to calculate min diff while traversing inorder in BST.

### Code

```cpp
class Solution {
private:
    int minDiff = INT_MAX;
    int prev = -1;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev != -1) minDiff = min(minDiff, root->val - prev);
        prev = root->val;
        inorder(root->right);
    }

public:
    int
    getMinimumDifference(TreeNode* root)
    {
        inorder(root);
        return minDiff;
    }
};
```
