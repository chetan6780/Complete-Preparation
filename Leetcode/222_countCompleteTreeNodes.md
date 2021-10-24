# [222. Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/) 🌟🌟

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

### O(N) Time

- we Can traverse the whole tree and count the number of nodes.

### O(log N \* log N) Time

- The idea behind the algorithm is - A complete binary tree has `2^h - 1` nodes, where `h` is the height of the tree.
- so we get the left and right hight of the tree.
- if the are equal, then we can directly return `2^(left) - 1`
- else we check for its right and left subtree and return `1 + countNodes(root->left) + countNodes(root->right);`

### Code-1:

```cpp
class Solution{
private:
    int leftHeight(TreeNode *root){
        if (root == NULL) return 0;
        return 1 + leftHeight(root->left);
    }
    int rightHeight(TreeNode *root){
        if (root == NULL) return 0;
        return 1 + rightHeight(root->right);
    }

public:
    int countNodes(TreeNode *root){
        if(root == NULL) return 0;

        int left = leftHeight(root);
        int right = rightHeight(root);
        if (left == right) return ((1 << (left)) - 1); //pow(2,left)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```

### Code-2:

```cpp
class Solution{
public:
    int countNodes(TreeNode *root){
        if (root == NULL) return 0;

        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0;

        while (l){ hl++; l = l->left;}
        while (r){ hr++; r = r->right;}
        if (hl == hr) return (1 << (hl)) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
