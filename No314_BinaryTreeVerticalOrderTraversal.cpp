// 314. Binary Tree Vertical Order Traversal

// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

// Examples:

// Given binary tree [3,9,20,null,null,15,7],
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7
// return its vertical order traversal as:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// Given binary tree [3,9,8,4,0,1,7],
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
// return its vertical order traversal as:
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]
// Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
// return its vertical order traversal as:
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]



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
    // Traversal the tree and set col number
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // set root's col number 0
        vector<vector<int> > res;

        if(!root) return res;
        map<int, vector<int> > m; // key for col, value for node

        setCol(root, m, 0);

        for(auto item : m){
            res.push_back(item.second);
        }

        return res;
        
    }
    // didn't consider the level sequence
    // dfs, so need bfs
    // void setCol(TreeNode* root, map<int, vector<int> >& m, int col){
    //     if(!root) return;
    //     m[col].push_back(root->val);
    //     setCol(root->left, m, col-1);
    //     setCol(root->right, m, col+1);
    // }

    void setCol(TreeNode* root, map<int,vector<int> >& m, int col){
        queue<pair<TreeNode*, int> > q;
        q.push({root, col});

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            m[top.second].push_back(top.first->val);
            if(top.first->left)
                q.push({top.first->left, top.second - 1});
            if(top.first->right)
                q.push({top.first->right, top.second + 1});
        }
    }
};




