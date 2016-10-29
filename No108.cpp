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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
    	return balancedBST(nums, 0 , nums.size()-1);
    }
private:
	TreeNode* balancedBST(vector<int>& nums, int start, int end)
	{
		if(start>end)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(nums[start+(end-start)/2]);
		root->left = balancedBST(nums, start, start+(end-start)/2-1);
		root->right = balancedBST(nums, start+(end-start)/2+1, end);
		return root;
	}
};