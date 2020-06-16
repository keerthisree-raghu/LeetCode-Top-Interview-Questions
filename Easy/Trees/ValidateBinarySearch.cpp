// VALIDATE BINARY SEARCH

/*  PROBLEM:
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    1. The left subtree of a node contains only nodes with keys less than the node's key.
    2. The right subtree of a node contains only nodes with keys greater than the node's key.
    3. Both the left and right subtrees must also be binary search trees.
*/

/*  EXAMPLES:

    Input: [2,1,3]
    Output: true
    Explanation: All conditions are satisfied
        2
       / \
      1   3   

    Input: [5,1,4,null,null,3,6]
    Output: False
    Explanation: The root node's value is 5 but its right child's value is 4.
        5
       / \
      1   4
         / \
        3   6
*/

/*  APPROACH: DFS Inorder Traversal - O(n)
    1. If the tree is empty, return true.
    2. Check if each element in the inorder traversal (left->node->right) of the list is smaller than the next element.
       min < value < max
    3. Recursively check if the right and left sub-trees follow the condition.
        a. If the condition fails, return false.
        b. If the conditions do not fail and value of the node becomes NULL (end of the tree), return true.
*/

// SOLUTION:
#include <bits/stdc++.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool depthFirstSearch(TreeNode *root, long min, long max) {
        if(root == NULL) {
            return true;
        }
        // Condition: min < root->val < max
        if(!(min < root->val && max > root->val)) {
            return false;
        }
        // Recursively call the function to check if both left and right sub-trees follow the condition
        return depthFirstSearch(root->left, min, root->val) && depthFirstSearch(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return depthFirstSearch(root, -LONG_MAX, LONG_MAX);
    }
};