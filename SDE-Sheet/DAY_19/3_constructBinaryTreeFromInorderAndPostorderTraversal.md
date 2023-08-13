# [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 🌟🌟

Given two integer arrays `inorder` and `postorder` where `inorder` is the `inorder` traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

### solution

-   To solve this problem we need to remember inorder and postorder of tree
-   Inorder = left, root, right
-   Postorder = left, right, root
-   Since we can find root of the tree from back of postorder array, the process is opposite of previous problem(inorder and preorder)
-   here we start from last element of postorder and decrease root index as we go
-   Also first we create right subtree and then left as compared to preorder where we built left first and then right.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder, int& rootIndex, int inStart, int inEnd, map<int, int>& inorderMap)
    {
        if (rootIndex < 0 || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[rootIndex]);
        int inorderIndex = inorderMap[postorder[rootIndex]]; // optimized with map
        rootIndex--; // Decrease rootIndex

        // (inStart, inorderIndex - 1), (inorderIndex + 1, inEnd) = leftSubtree, rightSubtree
        // build right subtree first, then left (reverse of preorder)
        root->right = buildTreeHelper(postorder, inorder, rootIndex, inorderIndex + 1, inEnd, inorderMap);
        root->left = buildTreeHelper(postorder, inorder, rootIndex, inStart, inorderIndex - 1, inorderMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int inStart = 0, inEnd = inorder.size() - 1, rootIndex = postorder.size() - 1;
        TreeNode* root = buildTreeHelper(postorder, inorder, rootIndex, inStart, inEnd, inMap);
        return root;
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
