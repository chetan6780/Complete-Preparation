# [99. Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/) 


### Recursive - using inorder traversal

-   We know that inorder traversal of BST is sorted, so we can use this fact to find the two nodes swapped.(In question it's confirmed that only two nodes are swapped)
-   **TC: O(n)**

### Code

```cpp
class Solution {
public:
    TreeNode *firstNode, *secondNode, *prevNode;
    void recoverTree(TreeNode* root)
    {
        inorder(root);
        // swap the values of misplaced nodes
        swap(firstNode->val, secondNode->val);
    }
    void inorder(TreeNode* root)
    {
        if (root == NULL) return;

        inorder(root->left);

        if (prevNode!=NULL && root->val < prevNode->val) {
            // set first node
            if (firstNode == NULL) firstNode = prevNode;
            // set/update second node
            secondNode = root;
        }

        // update previous node
        prevNode = root;

        inorder(root->right);
    }
};
```
