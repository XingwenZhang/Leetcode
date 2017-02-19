/*101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.*/

//recursively method 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
/*public:
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
};*/


//recursively, method 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(root == NULL){
    		return true;
    	}    
    	return isMirror(root->left, root->right);
    }
private:
	bool isMirror(TreeNode *left, TreeNode *right){
		if(!left && !right){
			return true;
		}
		else if((!left && right) || (left && !right) || (left->val != right->val) || 
			!isMirror(left->left, right->right) || !isMirror(left->right, right->left)){
			return false;
		}
		else{
			return true;
		}
	}
};*/


//iteratively, method 3
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
        	return true;
        }
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
        	TreeNode *left = q1.front();
        	TreeNode *right = q2.front();
        	q1.pop();
        	q2.pop();

        	// here must be continue, not return true, because it is possible that in queue, there are still other elements
        	if(left == NULL && right == NULL){
        		continue;
        	}
        	if(left == NULL || right == NULL){
        		return false;
        	}
        	if(left->val != right->val){
        		return false;
        	}
        	q1.push(left->left);
        	q1.push(left->right);
        	q2.push(right->right);
        	q2.push(right->left);
        }
        return true;
    }
};