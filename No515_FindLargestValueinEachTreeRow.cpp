// 515. Find Largest Value in Each Tree Row

// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]


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
    // Layer traversal, BFS
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        int max = INT_MIN;
        //res.emplace_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                if(node->val > max){
                    max = node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else if(!q.empty()){
                q.push(NULL);
                res.emplace_back(max);
                max = INT_MIN;
            }
            
        }
        res.emplace_back(max);
        return res;
    }
};