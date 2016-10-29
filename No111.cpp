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
    int minDepth(TreeNode* root) 
    {
        return countDepth(root);
    }
private: 
	int countDepth(TreeNode* root)
	{
		if(root==NULL)
		{
			return 0;
		}
		auto left = countDepth(root->left);
		auto right = countDepth(root->right);

		if(left&&right)
		{
			return min(left,right)+1;
		}
		else if(left && !right)
		{
			return left+1;
		}
		else
		{
			return right+1;
		}
	}
};