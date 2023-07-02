# [114. Flatten Binary Tree to Linked List](./Day_33/114_flattenBinaryTreeToLinkedList.md)

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

-   We can observe that the resultant tree is same as postorder traversal of binary tree with right node traversed first and root's right is previous node in traversal.
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

### Code

```cpp
class Solution {
public:
    void flatten(TreeNode* root)
    {
        // morris traversal
        TreeNode* cur = root;
        while (cur)
        {
            if (cur->left)
            {
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
