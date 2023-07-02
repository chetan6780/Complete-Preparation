# [889. Construct Binary Tree from Preorder and Postorder Traversal](./Day_33/889_constructBinaryTreeFromPreorderAndPostorderTraversal.md)

### Solution

### Code

```cpp
class Solution {
public:
    int idx = 0;
    TreeNode* buildTree(vector<int> preorder, vector<int> postorder, int l, int r, int size)
    {
        if (idx > size || l > r) return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        if (l == r) return root;
        int i;
        for (i = l; i <= r; i++) {
            if (preorder[idx] == postorder[i])
                break;
        }
        if (l <= r) {
            root->left = buildTree(preorder, postorder, l, i, size);
            root->right = buildTree(preorder, postorder, i + 1, r - 1, size);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        if (preorder.size() == 0) return NULL;
        return buildTree(preorder, postorder, 0, preorder.size() - 1, preorder.size());
    }
};
```
