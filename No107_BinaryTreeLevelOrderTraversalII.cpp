// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


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
	// BFS and reverse the result
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL){
        	return res;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
        	vector<int> level;
        	int levelLen = nodes.size();
        	for(int i=0; i<levelLen; i++){
        		TreeNode *node = nodes.front();
        		nodes.pop();
        		if(node->left){
        			nodes.push(node->left);
        		}
        		if(node->right){
        			nodes.push(node->right);
        		}
        		level.push_back(node->val);
        	}
        	res.push_back(level);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};