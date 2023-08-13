# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 🌟🌟

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

### Solution

-   To solve this problem we need to remember preorder and inorder of tree
-   Preorder = root, left, right
-   Inorder = left, root, right
-   So We can notice that if we start from root we will get root of the tree
-   by finding position of root in inorder we can say that, entire section which is on left to the root is its left subtree and right of the root is right subtree.
-   by dividing it we again got a smaller subtree, so we need to also it recursively by dividing till its base condition
-   We can loop over to inorder array to find elements index, but it will add extra O(N) time complexity per operation.
-   so instead of that we can use map to store indexes of inorder to reduce the time complexity.
-   **TC: O(N)**
-   **SC: O(N)**

![105-leetcode](/assets/105-leetcode.png)

### code

```cpp
class Solution {
    TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder, int& rootIndex, int inStart, int inEnd, map<int, int>& inorderMap)
    {
        if (rootIndex >= preorder.size() || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[rootIndex]);
        int inorderIndex = inorderMap[preorder[rootIndex]]; // optimized with map
        rootIndex++; // Increase rootIndex

        // (inStart, inorderIndex - 1), (inorderIndex + 1, inEnd) = leftSubtree, rightSubtree
        root->left = buildTreeHelp(preorder, inorder, rootIndex, inStart, inorderIndex - 1, inorderMap);
        root->right = buildTreeHelp(preorder, inorder, rootIndex, inorderIndex + 1, inEnd, inorderMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int inStart = 0, inEnd = inorder.size() - 1, rootIndex = 0;
        TreeNode* root = buildTreeHelp(preorder, inorder, rootIndex, inStart, inEnd, inMap);
        return root;
    }
};
```
