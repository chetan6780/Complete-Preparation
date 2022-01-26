# [1305. All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

### Most intuitive Solution

-   Traversal with any order and get all the nodes of the BST and then sort them.

### By inorder traversal and merge sort

-   We know that inorder traversal of BST gives us the sorted list.
-   Then we can merge these two lists into one using merge technique similar to merge sort.

### Code

```cpp
class Solution {
private:
    void inorder(vector<int>& v, TreeNode* root)
    {
        if (root == NULL) return;
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }
    void mergeSortedLists(vector<int>& res, vector<int>& v1, vector<int>& v2)
    {
        int i = 0, j = 0;
        int n = v1.size(), m = v2.size();

        while (i < n && j < m) {
            if (v1[i] < v2[j]) {
                res.push_back(v1[i++]);
            } else {
                res.push_back(v2[j++]);
            }
        }
        while (i < n)
            res.push_back(v1[i++]);
        while (j < m)
            res.push_back(v2[j++]);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> res;
        vector<int> v1, v2;

        inorder(v1, root1);
        inorder(v2, root2);
        mergeSortedLists(res, v1, v2);

        return res;
    }
};
```
