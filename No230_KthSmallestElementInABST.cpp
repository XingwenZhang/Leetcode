// 230. Kth Smallest Element in a BST

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note: 
// You may assume k is always valid, 1 ? k ? BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.


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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted_array;
        helper(root, sorted_array);
        return sorted_array[k-1];
    }
private:
    void helper(TreeNode* root, vector<int>& vec){
        if(!root){
            return;
        }
        helper(root->left, vec);
        vec.push_back(root->val);
        helper(root->right, vec);
    }
};