# [Flatten Binary Tree to Linked List](./Day_33/114_flattenBinaryTreeToLinkedList.md) 🌟

### Preorder Traversal

-   We can observe that the resultant tree is same as preorder traversal of binary tree.
-   so we get preorder traversal of tree and start creating resultant tree. It's right will be next node in traversal and left will be null.
-   **TC: O(N)**
-   **SC: O(N)**

### Code

```cpp
class Solution {
private:
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

public:
    void flatten(TreeNode* root)
    {
        vector<int> ans;
        preorder(root, ans);
        int n = ans.size();
        for (int i = 1; i < n; i++) {
            root->right = new TreeNode(ans[i]);
            root->left = NULL;
            root = root->right;
        }
        return;
    }
};
```

### Postorder Traversal with right node first

-   We can observe that the resultant tree is same as postorder traversal of binary tree with right node traversed first and root's right is previous node of traversal.
-   **TC:O(N)**
-   **SC:O(N)**

### Code

```cpp
class Solution {
private:
    TreeNode* prev = NULL;

public:
    void flatten(TreeNode* root)
    {
        // classic postorder traversal, with prev value assigned to root->right and root->left as null
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
```

### Iterative version of above solution

### Code

```cpp
class Solution {
public:
    void flatten(TreeNode* root)
    {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur) {
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
                cur->left = NULL;
                if (!st.empty()) cur->right = st.top();
            }
        }
    }
};
```

### Morris Traversal

-   To optimize the O(N) space complexity we will use morris traversal
-   This algorithm modifies the given binary tree in-place to transform it into a linked list where the right child of each 1. node becomes the next node in the list

1. Start at the root node.
2. Initialize the current node as the root.
3. While the current node is not null:
   a. If the current node has no left child, visit the current node and move to its right child.
   b. If the current node has a left child:
    i. Find the rightmost node in the left subtree of the current node. This node is called the "predecessor."
    ii. If the predecessor's right pointer is null, set it to point to the current node, move to the left child, and go back to step 3.
    iii. If the predecessor's right pointer is already pointing to the current node, restore the original tree structure, visit the current node, and move to its right child.
4. Repeat steps 3 until the current node becomes null.

### Code

```cpp
class Solution {
public:
    void flatten(TreeNode* root){
        // morris traversal
        TreeNode* cur = root;
        while (cur){
            if (cur->left){
                TreeNode* pre = cur->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
```
