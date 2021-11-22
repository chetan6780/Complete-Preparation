# [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) 🌟🌟

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

### Solution

1. **find the key node:** there are **3 cases**

```cpp
    if(key < root) -> find in left subtree
    else if(key > root) -> find in right subtree
    else (key==root) -> delete the node
```

2. **Now delete the node:** there are **3 cases**

```cpp
    if leaf node(0 child)  -> delete(node) and return NULL
    else if node having 1 child  -> delete(node) and return the child
    else  (node having 2 children){
      i) find smallest node (leftmost) in the right subtree of the key
      ii) copy the smallest node value with key node
      iii) delete that smallest node from right subtree (as it have only 1 or 0 child)}
```

**Alternative: In the condition of node having 2 children, we can also find largest node (rightmost) of left subtree of the key.**

### Code

```cpp
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (!root) return NULL;

        if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else { // root->val ==  key
            // leaf node (0 child)
            if (!root->left && !root->right) {
                delete (root);
                return NULL;
            }

            // only 1 child
            if (!root->left || !root->right) {
                TreeNode* ret = root->left ? root->left : root->right;
                delete (root);
                return ret;
            }

            // 2 children, find min of right subtree
            TreeNode* temp = root->right;
            while (temp && temp->left)
                temp = temp->left;

            // updating and deleting node (like swapping min of right subtree with root)
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val); // same node as 1 or 0 child
        }
        return root;
    }
};
```
