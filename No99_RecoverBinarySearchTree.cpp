// 99. Recover Binary Search Tree

// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n) space
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> vals;
        in_order(root, nodes, vals);
        sort(vals.begin(), vals.end());
        for(int i=0; i<nodes.size(); i++){
            nodes[i]->val = vals[i];
        }
    }

    void in_order(TreeNode* root, vector<TreeNode*>& nodes, vector<int>& vals){
        if(!root)
            return;
        in_order(root->left, nodes, vals);
        nodes.emplace_back(root);
        vals.emplace_back(root->val);
        in_order(root->right, nodes, vals);
    }
};


// Morris Traversal O(1) space, but this method needs to be modified
class Solution{
public:
    void recoverTree(TreeNode* root){
        TreeNode* cur = root;
        TreeNode* prev = nullptr;

        while(cur != nullptr){
            // If cur->left is null
            if(!cur->left){
                cout << cur->val;
                cur = cur->right;
            }
            else{
                prev = cur->left;
                while(prev->right || prev->right != cur){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = nullptr;
                    cout << cur->val;
                    cur = cur->right;
                }
            }
        }
    }
};

// Solution based on Morris Traversal O(1) space
class Solution{
public:
    void recoverTree(TreeNode* root){
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr, *second = nullptr, *parent = nullptr;
        while(cur){
            if(!cur->left){
                if(parent && parent->val > cur->val){
                    if(!first)
                        first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            }
            else{
                prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                if(!prev->right){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    if(parent && parent->val > cur->val){
                        if(!first)
                            first = parent;
                        second = cur;
                    }
                    prev->right = nullptr;
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        if(first && second)
            swap(first->val, second->val);
    }
};






