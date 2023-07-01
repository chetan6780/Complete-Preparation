# [Boundary traversal of binary tree](https://www.codingninjas.com/studio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems) 🌟🌟🌟

You have been given a binary tree of integers. Your task is to print the boundary nodes of this binary tree in anti-clockwise direction starting from the root.

### Solution

-   To get boundary nodes, we first need all the left nodes excluding leaf nodes.
-   Then we need all the leaf nodes.
-   And finally we need all the right nodes excluding leaf nodes in reverse order.
-   the code is self explanatory for all the functions.

### Code

```cpp
#include <bits/stdc++.h>

bool isLeaf(TreeNode<int>* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}

void addLeftBoundary(TreeNode<int>* root , vector<int> &res){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(isLeaf(curr)==false)res.push_back(curr->data);
        if(curr->left)curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(TreeNode<int>* root , vector<int> &res){
    TreeNode<int>* curr = root->right;
    stack<TreeNode<int>*> st;
    while(curr){
        if(isLeaf(curr)==false)st.push(curr);
        if(curr->right)curr = curr->right;
        else curr = curr->left;
    }
    while(!st.empty()){
        res.push_back(st.top()->data);
        st.pop();
    }
}

void addLeaves(TreeNode<int>* root , vector<int> &res){
    if(!root)return;
    if(isLeaf(root)==true){
        res.push_back(root->data);
        return;
    }
    if(root->left)addLeaves(root->left,res);
    if(root->right)addLeaves(root->right,res);
}


vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root)return res;
    if(isLeaf(root)==false){
        res.push_back(root->data);
    }
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
}
```
