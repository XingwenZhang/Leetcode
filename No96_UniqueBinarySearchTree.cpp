// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


class Solution {
public:
	// Dynamic Programming to solve this problem
	// [1..n] could divide into two parts, if i is the root of BST
	// 1..i-1 as the left BST, i+1..n as the right BST
	// then DP[i, n] = bst(i-1)*bst(n-i)
	// and the final result is bst(n) = DP(1,n)..+DP(n,n)
	// don't forget empty BST
    int numTrees(int n) {
        vector<int> bst(n+1, 0);
        bst[0] = 1;
        bst[1] = 1;
        for(int i=2; i<=n; i++){
        	for(int j=1; j<=i; j++){
        		bst[i] += bst[j-1] * bst[i-j];
        	}
        }
        return bst[n];

    }
};