// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root){
            return res;
        }
        string path = to_string(root->val);
        BinaryTreeHelper(root, path, res);
        return res;
    }
private:
	void BinaryTreeHelper(TreeNode *node, string path, vector<string> &res){
		if(!node->left && !node->right){
			res.push_back(path);
			return;
		}
		if(node->left){
			string left_path = path + "->" + to_string(node->left->val);
			BinaryTreeHelper(node->left, left_path, res);
		}
		if(node->right){
			string right_path = path + "->"+to_string(node->right->val);
			BinaryTreeHelper(node->right, right_path, res);
		}
	}
};