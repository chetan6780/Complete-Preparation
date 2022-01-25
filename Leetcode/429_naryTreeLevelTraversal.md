# [429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) 🌟🌟

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

### This question is in continuation with **A general approach to level order traversal questions** series.

**Previous Questions**

1. [Binary tree level order traversal](./102_btLevelOrderTraversal.md)
2. [Binary tree level order traversal - II](./107_btLevelOrderTraversalII.md)
3. [Binary tree zig-zag level order traversal](./103_btZigzagLevelOrderTraversal.md)
4. [Average of levels](637_averageOfLevels.md)
5. [Binary tree right side view](./199_binaryTreeRightSideView.md)
6. [largest value in each tree row](./515_findLargestValueInEachTreeRow.md)
7. [Populating next right pointer](./116_populatingNextRightPointer.md)

### Recursive solution

-   The algorithm is same as the first question in the series, except that we traverse all the children of the root node, not just left and right.

### Code

```cpp
class Solution {
private:
    void levelOrderDFS(vector<vector<int>>& res, Node* root, int level)
    {
        if (root == NULL) return;

        if (level == res.size()) res.push_back({});
        res[level].push_back(root->val);

        for (auto node : root->children) {
            levelOrderDFS(res, node, level + 1);
        }
    }

public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> res;
        levelOrderDFS(res, root, 0);
        return res;
    }
};
```

### Iterative solution

-   The algorithm is same as the first question in the series, except that we push all the children of the root node in queue, not just left and right.

### Code

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> currlevel;
            for (int i = 0; i < sz; i++) {
                Node* temp = q.front(); q.pop();

                for (auto n : temp->children)
                    q.push(n);

                currlevel.push_back(temp->val);
            }
            res.push_back(currlevel);
        }
        return res;
    }
};
```
