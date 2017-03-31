// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 


class Solution {
public:
	// 26 as a cycle
    string convertToTitle(int n) {
    	int a= n, b=-1;
    	
    	string res;
    	while(a!=0){
    		b = (a-1) % 26;
    		a = (a-1) / 26;
    		res.push_back('A'+b);
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
};