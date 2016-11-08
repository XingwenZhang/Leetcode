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
    int sumNumbers(TreeNode* root) 
    {
    	return sumHelper(root,0);
    }
private:
	int sumHelper(TreeNode* root, int num)
	{
		if(!root) return 0;
		if(!root->left && !root->right) return num*10+root->val;
		return sumHelper(root->left, num*10+root->val)+sumHelper(root->right, num*10+root->val);
	}
};



class Solution
{
public:
	int sumNumbers(TreeNode* root)
	{
		int sum = 0;
		sumHelper(root, sum, 0);
		return sum;
	}
private:
	void sumHelper(TreeNode* root, int& sum, int num)
	{
		if(!root)
		{
			return ;
		}
		num = num*10+root->val;
		if(!root->left && !root->right)
		{
			sum += num;
			return;
			//return sum;
		}
		sumHelper(root->left, sum, num);
		sumHelper(root->right, sum, num);
	}
};