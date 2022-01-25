# [116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) 🌟🌟

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

### This question is in continuation with **A general approach to level order traversal questions** series.

**Previous Questions**

1. [Binary tree level order traversal](./102_btLevelOrderTraversal.md)
2. [Binary tree level order traversal - II](./107_btLevelOrderTraversalII.md)
3. [Binary tree zig-zag level order traversal](./103_btZigzagLevelOrderTraversal.md)
4. [Average of levels](637_averageOfLevels.md)
5. [Binary tree right side view](./199_binaryTreeRightSideView.md)
6. [largest value in each tree row](./515_findLargestValueInEachTreeRow.md)

-   Next 2 solutions are part of the series other are not.

### Recursive Solution

-   self explanatory

### Code

```cpp
class Solution {
private:
    void connectDFS(Node* root)
    {
        if (root == NULL || root->left == NULL) // check if left is NULL
            return;

        root->left->next = root->right; // next pointer of root's left

        if (root->next != NULL) // if root's next exist
            root->right->next = root->next->left; // next pointer of root's right

        connectDFS(root->left);
        connectDFS(root->right);
    }

public:
    Node* connect(Node* root)
    {
        connectDFS(root);
        return root;
    }
};
```

### Iterative Solution

-   Self explanatory

### Code

```cpp
class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* temp = q.front(); q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);

                // if its last node it's next is NULL else q.front()(next left node)
                temp->next = (i == sz - 1 ? NULL : q.front());
            }
        }
        return root;
    }
};
```

### O(N) Time and O(N) space

-   Using level order traversal technique and NULL.
-   if current node is null and q is not empty, then push NULL into q.
-   else set current node's next to q's front.
-   push left and right in the queue , if they are not NULL.

### Code

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node *curr=q.front();
            q.pop();

            if(curr==NULL){
                if(!q.empty()) q.push(NULL);
            }else{
                curr->next = q.front();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        return root;
    }
};
```

### O(N) Time and O(1) space

-   level order traversal with root and its child,just dry run once you get the idea.

### Code

```cpp
class Solution{
public:
    Node *connect(Node *root){
        if (root == NULL) return root;

        Node *pre = root;
        Node *cur = NULL;

        while (pre->left){
            cur = pre;
            while (cur){
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
};
```
