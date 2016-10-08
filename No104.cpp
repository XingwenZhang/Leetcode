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
    int maxDepth(TreeNode* root) {
   		return DFS(root,0);

   	}
private:
	int DFS(TreeNode* root, int depth)
	{
		if(root==NULL)
		{
			return depth;
		}
		return std::max(DFS(root->left,depth+1),DFS(root->right,depth+1))；
	}
};