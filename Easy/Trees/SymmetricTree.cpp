// SYMMETRIC TREE

/*  PROBLEM:
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*/ 

/*  EXAMPLES:

    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
        1
       / \
      2   2
     / \ / \
    3  4 4  3    

    But the following [1,2,2,null,3,null,3] is not:
        1
       / \
      2   2
       \   \
       3    3
*/

/*  APPROACH: Recursive - O(n)
    1. Recursively check if the left sub-tree and right sub-tree are symmetric by:
        a. Checking if their roots have the same value.
        b. The right sub-tree of each tree is a mirror reflection of the left sub-tree of the other tree.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;

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
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if(t1 == NULL && t2 == NULL) {
            return true;
        }    
        if(t1 == NULL || t2 == NULL) {
            return false;
        }
        return (t1->val == t2->val)
            && isMirror(t1->right, t2->left)
            && isMirror(t1->left, t2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};