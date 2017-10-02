// 124. Binary Tree Maximum Path Sum

// Given a binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

// For example:
// Given the below binary tree,

//        1
//       / \
//      2   3
// Return 6.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        max_util(root, res);
        return res;
    }

    int max_util(TreeNode* node, int& global_max){
        if(node == nullptr)
            return 0;
        
        int left = max_util(node->left, global_max);
        int right = max_util(node->right, global_max);
        int res = (left>0?left:0) + (right>0?right:0) + node->val;
        global_max = max(global_max, res);

        return max(left, right) > 0 ? node->val + max(left, right) : node->val;

    }
};