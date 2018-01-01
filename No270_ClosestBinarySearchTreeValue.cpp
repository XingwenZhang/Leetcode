// 270. Closest Binary Search Tree Value

// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

// Note:
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.


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
    int closestValue(TreeNode* root, double target) {
        int small=INT_MAX;
        int big = INT_MAX;

        while(root){
            if(target > root->val){
                small = root->val;
                root = root->right;
            }
            else{
                big = root->val;
                root = root->left;
            }
        }

        if(big == INT_MAX){
            return small;
        }
        else if(small == INT_MAX){
            return big;
        }
        else{
            return abs(target - small) > abs(target - big) ? big : small;
        }
    }
};