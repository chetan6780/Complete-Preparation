# [95. Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/)

### DFS

-   If we can find all the possibles trees that can be generated from left subtree and right subtree, we can easily calculate the number of unique trees.
-   So for every node we calculate number of unique trees from left subtree and right subtree.

### Code

```cpp
class Solution {
private:
    vector<TreeNode*> generateTreesHelper(int start, int end)    {
        if (start > end) {
            return { NULL };
        }
        vector<TreeNode*> leftList, rightList, result;

        for (int i = start; i <= end; i++) {
            leftList = generateTreesHelper(start, i - 1);
            rightList = generateTreesHelper(i + 1, end);
            for (auto l : leftList) {
                for (auto r : rightList) {
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }
        return result;
    }

public:
    vector<TreeNode*> generateTrees(int n)    {
        return generateTreesHelper(1, n);
    }
};
```
