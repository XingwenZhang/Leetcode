/*235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// version 1, easy to understand
/*class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q || root==NULL){
        	return root;
        }
        //if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)) {
        if((root->val-p->val)*(root->val-q->val) < 0){
        	return root;
        }
        else if(root->val > p->val){
        	return lowestCommonAncestor(root->left, p, q);
        }
        else{
        	return lowestCommonAncestor(root->right, p, q);
        }
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// iterative method
/*class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
        	return root;
        }
        while((root->val-p->val)*(root->val-q->val)>0){
        	root = root->val > p->val ? root->left : root->right;
        }
        return root;
    }
};
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive method, but consice code

/*class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
        	return root;
        }
        if((root->val-p->val)*(root->val-q->val)>0){
        	return root->val > p->val ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q);
        }
        else{
        	return root;
        }
    }
};*/


// recursive method, more consice code

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
        	return root;
        }
        return (root->val-p->val)*(root->val-q->val)<=0 ? root : lowestCommonAncestor(root->val > p->val ? root->left : root->right, p, q);
    }
};
