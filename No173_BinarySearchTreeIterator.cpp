// 173. Binary Search Tree Iterator

// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->cur = 0;
        inorder_traversal(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(cur < vals.size()){
            return true;
        }
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return vals[cur++];
    }
private:
    int cur;
    vector<int> vals;
    void inorder_traversal(TreeNode *root){
        if(root){
            inorder_traversal(root->left);
            vals.push_back(root->val);
            inorder_traversal(root->right);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */