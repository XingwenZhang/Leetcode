// 144. Binary Tree Preorder Traversal

// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

// Note: Recursive solution is trivial, could you do it iteratively?



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         preorder_helper(root, res);
//         return res;
//     }
// private:
//     void preorder_helper(TreeNode *root, vector<int>& res){
//         if(root == NULL){
//             return;
//         }
//         res.push_back(root->val);
//         preorder_helper(root->left, res);
//         preorder_helper(root->right, res);
//     }

// };


// Iteratively
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        stack<TreeNode*> right_tree;
        preorder_helper(root, res, right_tree);
        while(!right_tree.empty()){
            root = right_tree.top();
            right_tree.pop();
            preorder_helper(root, res, right_tree);
        }
        return res;
    }
private:
    void preorder_helper(TreeNode *root, vector<int>& res, stack<TreeNode*>& right_tree){
        while(root){
            res.push_back(root->val);
            if(root->right){
                right_tree.push(root->right);
            }
            root = root->left;
        }
    }
};