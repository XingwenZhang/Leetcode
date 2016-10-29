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
	//in-order traversal 
    bool isValidBST(TreeNode* root) {
    	if(!root)
    	{
    		return true;
    	}
        inOrderTraversal(root);
        for(int i=0; i<seq.size()-1; i++)
        {
        	if(seq[i]>=seq[i+1])
        	{
        		return false;
        	}
        }
        return true;
    }
private:
	vector<int> seq;
	void inOrderTraversal(TreeNode* root)
	{
		if(root)
		{
			inOrderTraversal(root->left);
			seq.push_back(root->val);
			inOrderTraversal(root->right);
		}
	}

};