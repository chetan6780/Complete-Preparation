# [257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

### Recursive

```cpp
class Solution {
    void helper(TreeNode* root, string ans, vector<string>& res)
    {
        // if both root are null, push the ans string with root's value in res vector.
        if (root->left == NULL && root->right == NULL) {
            res.push_back(ans + to_string(root->val));
            return;
        }
        // if root's left is not null, recur to left by adding root's val and arrow in ans string
        if (root->left) {
            helper(root->left, ans + to_string(root->val) + "->", res);
        }
        // if root's right is not null, recur to right by adding root's val and arrow in ans string
        if (root->right) {
            helper(root->right, ans + to_string(root->val) + "->", res);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        int num = root->val;
        string ans;
        vector<string> res;
        helper(root, ans, res);
        return res;
    }
};
```

### Iterative

-   Iterative implementation of recursive solution

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        if (root == NULL)
            return res;
        stack<TreeNode*> st;
        stack<string> st_str;
        st.push(root);
        st_str.push(to_string(root->val));

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            string cur_str = st_str.top();
            st_str.pop();
            if (cur->left == NULL && cur->right == NULL) {
                res.push_back(cur_str);
            }
            if (cur->right != NULL) {
                st.push(cur->right);
                st_str.push(cur_str + "->" + to_string(cur->right->val));
            }
            if (cur->left != NULL) {
                st.push(cur->left);
                st_str.push(cur_str + "->" + to_string(cur->left->val));
            }
        }
        return res;
    }
};
```
