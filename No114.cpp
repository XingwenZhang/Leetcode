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
    void flatten(TreeNode* root) 
    {
    	if(root==nullptr)
    		return;
    	vector<TreeNode*> ans;
    	preOrder(root,ans);
    	for(int i=0; i<ans.size()-1; i++)
    	{
    		ans[i]->right = ans[i+1];
    		ans[i]->left = nullptr;
    	}
    	if(ans.size()>0)
    	{
    		ans[ans.size()-1]->right = nullptr;
    		ans[ans.size()-1]->left = nullptr;
    	}
    }
private:
	void preOrder(TreeNode* root, vector<TreeNode*>& store)
	{
		if(root)
		{
			store.push_back(root);
		}
		if(root->left)
		{
			preOrder(root->left, store);
		}
		if(root->right)
		{
			preOrder(root->right,store);
		}
	}
};