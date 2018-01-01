// 156. Binary Tree Upside Down

// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

// For example:
// Given a binary tree {1,2,3,4,5},
//     1
//    / \
//   2   3
//  / \
// 4   5
// return the root of the binary tree [4,5,2,#,#,3,1].
//    4
//   / \
//  5   2
//     / \
//    3   1  
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursion method
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        // If root is empty or root's left node is empty
        if(!root || !root->left) return root;

        auto l = root->left;
        auto r = root->right;

        auto res = upsideDownBinaryTree(l);

        l->left = r;
        l->right = root;

        root->left = nullptr;
        root->right = nullptr;

        return res;
    }
};


// Iterative method
class Solution{
public:
	TreeNode * upsideDownBinaryTree(TreeNode *root){
		TreeNode *cur = root, *next = NULL, *tmp = NULL, *prev = NULL;

		while(cur){
			next = cur->left;

			cur->left = tmp;
			tmp = cur->right;
			cur->right = prev;

			prev = cur;
			cur = next;
		}

		return prev; // the last cur
	}
};