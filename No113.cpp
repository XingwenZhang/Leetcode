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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
    	vector<vector<int> > paths;
    	vector<int> path;
    	pathSumHelper(root, sum, paths, path);
    	return paths;
    }
private:
	bool isLeaf(TreeNode* node)
	{
		if(!node->left && !node->right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void pathSumHelper(TreeNode* root, int sum, vector<vector<int> >& paths, vector<int>& path)
	{
		if(!root)
		{
			return;
		}
		path.push_back(root->val);
		if(isLeaf(root) && sum-root->val == 0)
		{
			paths.push_back(path);
		}
		pathSumHelper(root->left, sum-root->val, paths, path);
		pathSumHelper(root->right, sum-root->val, paths, path);
		path.pop_back();
	}
};