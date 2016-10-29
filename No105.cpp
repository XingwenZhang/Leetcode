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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
    	return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
	TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd)
	{
		if(preStart>preEnd)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[preStart]);
		int pos;
		for(int i=inStart; i<=inEnd; i++)
		{
			if(inorder[i]==root->val)
			{
				pos = i;
				break;
			}
		}
		root->left = buildTreeHelper(preorder, inorder, preStart+1, preStart+pos-inStart, inStart, pos-1);
		root->right = buildTreeHelper(preorder, inorder, preStart+pos-inStart+1, preEnd, pos+1, inEnd);
		return root;
	}
};