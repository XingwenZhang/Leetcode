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
    bool isBalanced(TreeNode* root) 
    {
        return checkBalance(root).second;
    }
private:
	pair<int, bool> checkBalance(TreeNode* root)
	{
		if(root==NULL)
		{
			return {0, true};
		}
		auto left = checkBalance(root->left);
		auto right = checkBalance(root->right);
		return {max(left.first, right.first)+1, left.second&&right.second&&abs(left.first-right.first)<=1}
	}
};