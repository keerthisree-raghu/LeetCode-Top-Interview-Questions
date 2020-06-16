// CONVERT SORTED ARRAY TO BINARY SEARCH TREE

/*  PROBLEM:
    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of 
    the two subtrees of every node never differ by more than 1.
*/

/*  EXAMPLE:
    Given the sorted array: [-10,-3,0,5,9],

    One possible answer is: [0,-3,9,-10,null,5], 
    which represents the following height balanced BST:

            0
           / \
         -3   9
         /   /
       -10  5
*/

/*  APPROACH:
    1. If the height of the tree is empty, return NULL.
    2. Find the middle element of the sorted array, which is the root of the tree.
    3. Initialize a new tree node with the value of the middle element of the sorted array.
    4. Indentify the sub-array that the mid-value belongs to and assign the node as the left or right node accordingly.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Tree is empty
        if(nums.size() == 0) {
            return NULL;
        }
        // To find the middle element of the sorted array (root)
        int mid = nums.size() / 2;
        // Initialize a new node with the value of the middle element of the sorted array
        TreeNode *newNode = new TreeNode(nums[mid]);
        
        if(mid - 1 >= 0) {
            vector<int> left(nums.begin(), nums.begin() + mid);
            // The node to the left of this node is the sub-vector from start to mid
            // End condition is when nums is empty
            newNode->left = sortedArrayToBST(left);
        }
        
        if(mid + 1 < nums.size()) {
            vector<int> right(nums.begin() + mid + 1, nums.end());
            // The node to the right of this node is the sub-vector from mid to end
            // End condition is when nums is empty
            newNode->right = sortedArrayToBST(right);
        }
        return newNode;
    }
};