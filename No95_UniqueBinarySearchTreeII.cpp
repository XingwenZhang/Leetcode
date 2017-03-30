// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3



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
	// BST's in-order traversal is sequential
	// So the tree can also use this property to construct
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode*> res;
            return res;
        }
        return generateTreesHelper(1, n);
    }
private:
	vector<TreeNode*> generateTreesHelper(int start, int end){
		vector<TreeNode*> tree;
		if(start > end){
			tree.push_back(NULL);
			return tree;
		}
		if(start == end){
			tree.push_back(new TreeNode(start));
			return tree;
		}
		vector<TreeNode*> left, right;
		for(int i = start; i<=end; i++){
			left = generateTreesHelper(start, i-1);
			right = generateTreesHelper(i+1, end);
			for(auto &l : left){
				for(auto &r : right){
					TreeNode *root = new TreeNode(i);
					root->left = l;
					root->right = r;
					tree.push_back(root);	
				}
			}
		}
		return tree;
	}
};