// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> pre;

        for(int i = 0; i<numRows; i++){
        	vector<int> temp(i+1, 1);
        	if(res.size() >= 1){
        		pre = res.at(res.size()-1);
        	}
        	for(int j = 1; j<i; j++){
        		temp[j] = pre[j-1]+pre[j];
        	}
        	res.push_back(temp);
        }

        return res;
    }
};