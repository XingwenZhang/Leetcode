// 669. Trim a Binary Search Tree

// Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

// Example 1:
// Input: 
//     1
//    / \
//   0   2

//   L = 1
//   R = 2

// Output: 
//     1
//       \
//        2
// Example 2:
// Input: 
//     3
//    / \
//   0   4
//    \
//     2
//    /
//   1

//   L = 1
//   R = 3

// Output: 
//       3
//      / 
//    2   
//   /
//  1

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* p = new TreeNode(0);
        p->left = root;
        p->left = trim_helper(p->left, L ,R);
        return p->left;
    }
    TreeNode* trim_helper(TreeNode* node, int L, int R){
        if(valid(node,L, R)){
            if(!node->left && node->right){
                node->right = trim_helper(node->right, L, R);
                // node->right = NULL;
            }
            else if(node->left && !node->right){
                node->left = trim_helper(node->left, L, R);
            }
            else{
                node->left = trim_helper(node->left, L, R);
                node->right = trim_helper(node->right, L, R);
            }
            return node;
        }
        else{
            if(!node){
                return NULL;
            }
            else if(node->left && !node->right){
                return trim_helper(node->left, L, R);
            }
            else if(!node->left && node->right){
                return trim_helper(node->right, L, R);
            }
            else{
                if(trim_helper(node->left, L, R)){
                    return trim_helper(node->left, L, R);
                }
                else{
                    return trim_helper(node->right, L, R);
                }
            }
        }
    }
    bool valid(TreeNode* node, int L, int R){
        if(node && node->val <= R && node->val >= L){
            return true;
        }
        return false;
    }
};