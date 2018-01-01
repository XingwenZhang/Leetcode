// 298. Binary Tree Longest Consecutive Sequence

// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// For example,
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Longest consecutive sequence path is 3-4-5, so return 3.
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

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
//     int longestConsecutive(TreeNode* root) {
//         if(!root) return 0;
//         return longest_tree_util(root, 1, 1);
//     }
//     int longest_tree_util(TreeNode* node, int max_len, int cur_len){
//         if(cur_len > max_len)
//             max_len = cur_len;
//         if(!node || (!node->left && !node->right))
//             return max_len;
//         if(node->left && !node->right){
//             if(node->val == node->left->val-1){
//                 return longest_tree_util(node->left, max_len, cur_len+1);
//             }
//             else{
//                 return longest_tree_util(node->left, max_len, 1);
//             }
//         }
//         else if(node->right && !node->left){
//             if(node->val == node->right->val-1){
//                 return longest_tree_util(node->right, max_len, cur_len+1);
//             }
//             else{
//                 return longest_tree_util(node->right, max_len, 1);
//             }
//         }
//         else if(node->left && node->right){
//             int lval = node->left->val;
//             int rval = node->right->val;
//             if(lval == rval){
//                 if(lval - node->val == 1){
//                     return max(longest_tree_util(node->left, max_len, cur_len+1), longest_tree_util(node->right, max_len, cur_len+1));
//                 }
//                 else{
//                     return max(longest_tree_util(node->left, max_len, 1), longest_tree_util(node->right, max_len, 1));
//                 }
//             }
//             else{
//                 if(lval - node->val == 1){
//                     return max(longest_tree_util(node->left, max_len, cur_len+1), longest_tree_util(node->right, max_len, 1));
//                 }
//                 else if(rval - node->val == 1){
//                     return max(longest_tree_util(node->left, max_len, 1), longest_tree_util(node->right, max_len, cur_len+1));
//                 }
//                 else{
//                     return max(longest_tree_util(node->left, max_len, 1), longest_tree_util(node->right, max_len, 1));
//                 }
//             }
//         }
//     }
// };


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
    int longestConsecutive(TreeNode* root) {
        return longest_tree_util2(root, nullptr, 0);
    }
    int longest_tree_util2(TreeNode* node, TreeNode* parent, int len){
        if(!node){
            return len;
        }
        len = (parent && node->val == parent->val+1) ? len+1 : 1;
        return max(len, max(longest_tree_util2(node->left, node, len), longest_tree_util2(node->right, node, len)));
    }
};