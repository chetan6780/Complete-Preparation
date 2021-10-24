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

### O(N) Time and O(N) space

- Using level order traversal technique and NULL.
- if current node is null and q is not empty, then push NULL into q.
- else set current node's next to q's front.
- push left and right in the queue , if they are not NULL.

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

<!-- TODO: Explanation -->

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
