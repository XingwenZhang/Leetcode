// 285. Inorder Successor in BST

// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

// Note: If the given node has no in-order successor in the tree, return null.

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
    // Successor is the node which is just bigger then p
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right != nullptr){ // If p has right sub tree
            // successor is the smallest in right sub tree
            auto node = p->right;
            while(node->left){
                node = node->left;
            }
            return node;
        }

        else{
            TreeNode* succ = nullptr;
            while(root){
                // p is left part, then root might be its succ
                if(p->val < root->val){
                    succ = root;
                    root = root->left;
                }
                else if(p->val > root->val){
                    root = root->right;
                }
                else{
                    break; // if current root is p, then return succ
                }
            }
            return succ;
        }
    }
};