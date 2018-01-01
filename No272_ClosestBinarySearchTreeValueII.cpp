// 272. Closest Binary Search Tree Value II

// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?


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
    // AC methods, max heap to store pair<diff, index>
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double,int> > max_heap;
        inOrder(root, target, k,max_heap);
        vector<int> res;

        while(!max_heap.empty()){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
    void inOrder(TreeNode* root, double target, int k, priority_queue<pair<double, int> >& heap){
        if(root == nullptr){
            return;
        }
        inOrder(root->left, target, k, heap);
        double diff = abs(root->val - target);

        if(heap.size() < k){
            heap.push({diff, root->val});
        }
        else{
            if(diff < heap.top().first){
                heap.pop();
                heap.push({diff, root->val});
            }
        }

        inOrder(root->right, target, k, heap);
    }
};



