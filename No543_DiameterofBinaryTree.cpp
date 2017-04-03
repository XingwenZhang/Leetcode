// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// Example:
// Given a binary tree 
//           1
//          / \
//         2   3
//        / \     
//       4   5    
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

// Note: The length of path between two nodes is represented by the number of edges between them.



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
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return max_len;
    }

private:
	int max_len_ = 0;
	int DFS(TreeNode *node){
		if(node == NULL){
			return 0;
		}

		int left_len = DFS(node->left);
		int right_len = DFS(node->right);

		if(left_len + right_len > max_len_){
			max_len_ = left_len + right_len;
		}

		// Update value
		return max(left_len + 1, right_len + 1);
	}
};