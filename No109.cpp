/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> sortedArray;
        while(head)
        {
        	sortedArray.push_back(head->val);
        	head = head->next;
        }
        return balancedBST(sortedArray, 0 ,sortedArray.size()-1);
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