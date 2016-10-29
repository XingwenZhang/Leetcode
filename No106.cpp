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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
    	 return buildTreeHelper(inorder,postorder, 0, inorder.size()-1, 0, postorder.size()-1);   
    }
private: 
	TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd)
	{
		if(posStart>posEnd)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(postorder[posEnd]);
		int pos;
		for(int i=inStart; i<=inEnd; i++)
		{
			if(inorder[i]==root->val)
			{
				pos = i;
				break;
			}
		}
		root->left = buildTreeHelper(inorder, postorder, inStart, pos-1, posStart, posStart+pos-inStart-1);
		root->right = buildTreeHelper(inorder, postorder, pos+1, inEnd, posStart+pos-inStart, posEnd - 1);
		return root;
	}
};