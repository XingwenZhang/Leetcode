/*102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
      	vector<vector<int> > res;
      	if(!root){
      		return res;
      	}

      	// bfs 
      	bfs(root, res);
      	return res;
    }

private: 
	//need to handle the level
	void bfs(TreeNode* root, vector<vector<int> >& res){
		queue<TreeNode*> q;
		q.push(root);
		q.push(NULL);
		vector<int> temp;
		while(!q.empty()){
			TreeNode *node = q.front();
			q.pop();
			if(node){
				temp.push_back(node->val);
				if(node->left){
					q.push(node->left);
				}
				if(node->right){
					q.push(node->right);
				}
			}
			else if(!q.empty()){
				q.push(NULL);
				res.push_back(temp);
				temp.clear();
			}
			// handle the last level
			if(!temp.empty() && q.empty()){
			    res.push_back(temp);
			}
		}
	}
};