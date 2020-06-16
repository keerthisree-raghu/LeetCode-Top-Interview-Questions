// BINARY TREE LEVEL ORDER TRAVERSAL

/*  PROBLEM:
    Given a binary tree, return the level order traversal of its nodes' values. 
    (ie, from left to right, level by level).
*/ 

/*  TESTCASE:

    Input: [3,9,20,null,null,15,7]
        3
       / \
      9  20
        /  \
       15   7
    Output:
    [
        [3],
        [9,20],
        [15,7]
    ]
*/

/*  APPROACH: Breadth First Traversal
    1. Initialize a two dimensional vector to store the array of elements from every level of the tree.
       Initialize a queue to store elements from every level of the tree in an inorder manner.
       Initialize a one-dimensional vector to store the elements that are removed from the queue.
    2. Push each node into the queue.
    3. Traverse the queue and remove the first element and store its value in a temporary variable.
    4. Push the elements from the queue in the order [current_node_value, left_node_value, right_node_value].
    5. When the nodes in a level have been stored in the array, push the completed array to the resultant array.
    6. Clear the array and repeat the process until the tree has been traversed completely.
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

// Breadth First Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Initialize a two-dimensional resultant vector
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        queue<TreeNode*> q;
        vector<int> v;
        // Push each node into the queue
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            TreeNode* temp;
            // Traverse the queue
            for(int i = 0; i < length; i++) {
                // Remove the first element from the queue and store it in a temporary variable
                temp = q.front();
                q.pop();
                // node -> left -> right
                // Push the value of the node removed into a vector
                v.emplace_back(temp->val);
                // Push the left node into the vector if it exists
                if(temp->left) {
                    q.push(temp->left);
                }
                // Push the right node into the vector if it exists
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            // Push the completed level of nodes into the two-dimensional resultant vector
            res.emplace_back(v);
            // Reset the vector
            v.clear();
        }
        return res;
    }
};
