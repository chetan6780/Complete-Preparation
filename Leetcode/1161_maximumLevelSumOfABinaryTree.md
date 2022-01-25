### This question is in continuation with **A general approach to level order traversal questions** series.

**Previous Questions**

1. [Binary tree level order traversal](./102_btLevelOrderTraversal.md)
2. [Binary tree level order traversal - II](./107_btLevelOrderTraversalII.md)
3. [Binary tree zig-zag level order traversal](./103_btZigzagLevelOrderTraversal.md)
4. [Average of levels](637_averageOfLevels.md)
5. [Binary tree right side view](./199_binaryTreeRightSideView.md)
6. [largest value in each tree row](./515_findLargestValueInEachTreeRow.md)
7. [Populating next right pointer](./116_populatingNextRightPointer.md)
8. [n-ary tree level order traversal](./429_naryTreeLevelOrderTraversal.md)

-   Just level order traversal and finding the max sum level

### Recursive Solution

### Code

```cpp
class Solution {
private:
    void maxLevelSumDFS(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if (root == NULL)
            return;

        if (level == res.size()) res.push_back({});
        res[level].push_back(root->val);

        maxLevelSumDFS(res, root->left, level + 1);
        maxLevelSumDFS(res, root->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode* root)
    {
        vector<vector<int>> res;
        int maxLevel = 0, maxSum = INT_MIN;
        maxLevelSumDFS(res, root, 0);

        int cnt = 0;
        for (auto& x : res) {
            int currSum = accumulate(x.begin(), x.end(), 0);
            cnt++;
            if (currSum > maxSum) {
                maxSum = currSum;
                maxLevel = cnt;
            }
        }
        return maxLevel;
    }
};
```

### Iterative Solution

### Code

```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root)
    {
        int maxLevel = 0;
        if (root == NULL) return maxLevel;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int levelCnt = 0;
        while (!q.empty()) {
            ++levelCnt;
            int sz = q.size();
            int levelSum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                levelSum += node->val;
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = levelCnt;
            }
        }
        return maxLevel;
    }
};
```
