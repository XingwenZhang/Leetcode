// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


class Solution {
public:

	// This is a very elegant solution, reference https://discuss.leetcode.com/topic/1011/what-is-the-best-solution-for-gray-code-problem-no-extra-space-used-and-no-recursion
    vector<int> grayCode(int n) 
	{         
		vector<int> result(1, 0);        
		for (int i = 0; i < n; i++) {
			int curCount = result.size();
        	// push back all element in result in reverse order
			while (curCount) {
				curCount--;
				// From the last element of result to the first one
				int curNum = result[curCount];
				curNum += (1<<i);
				result.push_back(curNum);
			} 
		}
		return result;
	}
};