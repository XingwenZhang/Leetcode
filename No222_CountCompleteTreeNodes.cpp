// 222. Count Complete Tree Nodes

// Given a complete binary tree, count the number of nodes.

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.



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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);

        // Complete left subtree
        if(l == r){
            return (1<<l) + countNodes(root->right);
        }
        else{
            return (1<<r) + countNodes(root->left);
        }
    }
private:
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1 + height(root->left);
    }
};