// MAXIMUM DEPTH OF BINARY TREE

/*  PROBLEM:
    Given a binary tree, find its maximum depth.

    The maximum depth is the number of nodes along the longest 
    path from the root node down to the farthest leaf node.
*/

/*  EXAMPLE:

    Input: [3,9,20,null,null,15,7]
    Output: 3
    Explanation:
        3       ---- 1
       / \
      9  20     ---- 2
        /  \
       15   7   ---- 3
*/

/*  APPROACH: Depth-First Search - O(n)
    1. If the tree is empty, return 0.
    2. Recursively calculate the maximum depth of the left sub-tree.
       maxDepth(tree->left_subtree)
    3. Recursively calculate the maximum depth of the right sub-tree.
       maxDepth(tree->right_subtree)
    4. Compare the values of the maximum depth of the left and right sub-trees in each recursive call.
    5. Add 1 to the maximum of the two depth values to account for the current node and return the maximum depth.
*/

// SOLUTION:
#include <bits/stdc++.h>

// Definition for a binary tree node
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
    // Helper function to calculate the maximum value of two integers
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        // Recursiely call the maxDepth() function for the left and right sub-trees
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};