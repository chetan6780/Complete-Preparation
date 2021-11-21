# [106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 🌟🌟

Given two integer arrays `inorder` and `postorder` where `inorder` is the `inorder` traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

### Solution

### Code-striver's

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    TreeNode* buildTreePostIn(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& mp)
    {
        if (postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIndx = mp[postorder[postEnd]];

        TreeNode* leftChild = buildTreePostIn(inorder, inStart, rootIndx - 1, postorder, postStart, postStart + rootIndx - inStart - 1, mp);
        TreeNode* rightChild = buildTreePostIn(inorder, rootIndx + 1, inEnd, postorder, postStart + rootIndx - inStart, postEnd - 1, mp);
        root->left = leftChild;
        root->right = rightChild;

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int inSize = inorder.size(), postSize = postorder.size();
        if (inSize != postSize) return NULL;

        map<int, int> mp; // mp to find index of a number in inorder in constant time
        for (int i = 0; i < inSize; ++i) mp[inorder[i]] = i; // mp[elem]=index in inorder

        return buildTreePostIn(inorder, 0, inSize - 1, postorder, 0, postSize - 1, mp);
    }
};
```

### Code - 2

```cpp
class Solution {
public:
    map<int, int>mp; // Stores (node -> index in inorder array)

    TreeNode* make_tree(int start, int end, int &idx, vector<int>& postorder, vector<int>& inorder){

		// If range for inorder is NOT valid then return NULL
        if(start > end) return NULL;

		// Create a node for our root node of current subtree
        TreeNode* root = new TreeNode(postorder[idx]);

		// Find position of current root in inorder array
        int i = mp[root->val];

		// Decrement our pointer to postorder array for our next upcoming root if any
        idx--;

		// Make a call to create right subtree, inorder range [i+1, end]
        root->right = make_tree(i+1, end, idx, postorder, inorder);

		// Make a call to create left subtree, inorder range [start, i-1]
        root->left = make_tree(start, i-1, idx, postorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;

		// Create (nodes -> index of inorder array) mapping
        for(int i{}; i<inorder.size(); ++i){

            mp[inorder[i]] = i;
        }
		// Create tree starting from root at position (n-1) in postorder array
		// Range for current inirder array : [0, n-1]
        return make_tree(0, inorder.size()-1, idx, postorder, inorder);
    }
};
```

-   **Time Complexity: O(N)** since we are visiting every node from postorder array at once and creating a node for it.

-   **Space Complexity: O(N)** since we are creating a mapping for every node that will contain its index for a node in inorder array.

### MUST READ

-   [[C++] EASY Intuitive Sol || Clean Recursive Code w/ Explanation || T.C:O(N)](<https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/1588934/C%2B%2B-EASY-Intuitive-Sol-oror-Clean-Recursive-Code-w-Explanation-oror-T.C%3AO(N)>)
