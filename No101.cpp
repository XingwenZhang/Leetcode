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
    bool isSymmetric(TreeNode* root) {
        preOrderForward(root);
        preOrderBackward(root);
        if(seq1==seq2)
        {
        	return true;
        }
        else
        {
        	return false;
        }
    }
private:
	vector<int> seq1;
	vector<int> seq2;
	void preOrderForward(TreeNode* root)
	{
		if(root)
		{
			if(!root->left && root->right)
			{
				root->left = new TreeNode(INT_MAX);
			}
			else if(root->left && !root->right)
			{
				root->right = new TreeNode(INT_MAX);
			}
			
			
			seq1.push_back(root->val);
			preOrderForward(root->left);
			preOrderForward(root->right);
			
		}
	}
	void preOrderBackward(TreeNode* root)
	{
		if(root)
		{
			
			seq2.push_back(root->val);
			preOrderBackward(root->right);
			preOrderBackward(root->left);
		}
	}
};