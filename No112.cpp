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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        return checkPath(root, sum);
    }
private:
	bool checkPath(TreeNode* root, int sum)
	{
		if(root!=NULL&&root->left==NULL && root->right==NULL && sum-root->val == 0)
		{
		    return true;
		}
		else if(root==NULL)
		{
		    return false;
		}
		auto left = checkPath(root->left, sum-root->val);
		auto right = checkPath(root->right, sum-root->val);
		return (left||right);
	}
};