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
    TreeNode* invertTree(TreeNode* root) {
    	if(root!=NULL)
       {
      	 	//俩种迭代方式
       		//方式1
        	std::swap(root->left,root->right);
           	invertTree(root->left);
           	invertTree(root->right);

           	//方式2
           	//invertTree(root->left);
           	//invertTree(root->right);
           	//std::swap(root->left,root->right);

           	//俩种方式的差异在于
           	//方式1是从节点的顶层开始交换
           	//方式2是从节点的底层开始交换
       }
       return root;
	}
};