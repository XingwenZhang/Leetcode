// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note: Given n will be between 1 and 9 inclusive.


// Because it only requires the kth permutation order
// so it has no need to construct all permutation. 
// it will TLE if permute all.
class Solution {
public:
    string getPermutation(int n, int k) {
        int product = 1;
        vector<int> permSum(n, 1);
        string res;
        vector<int> num;
        for(int i=1; i<=n; i++){
        	// num [1..n]
        	num.push_back(i);
        }

        for(int i=1; i<=n; i++){
        	product *= i;
        	// permSum contains the number of permutation of i
        	permSum[i-1] = product;
        }
        k--;
        for(int i=1; i<=n; i++){
        	// n-i-1, because index of permSum begins from 0
        	int index; 
        	if(i != n){
        		index = k/permSum[n-i-1];
        		// Update k
        		k -= index * permSum[n-i-1];
        	}
        	else{
        		index = k/1;
        		// Update k 
        		k -= index * 1;
        	}
        	res.append(to_string(num[index]));
        	// num[index] will not use
        	num.erase(num.begin() + index);
        }
        return res;
    }
};