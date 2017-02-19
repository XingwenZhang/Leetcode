/*240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

Subscribe to see which companies asked this question.*/


//binary search
//row by row binary search, time complexity is mlogn
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0){
            return false;
        }
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
        	if(binSearch(matrix[i], 0, n-1, target)){
        		return true;
        	}
        }
        return false;
    }
private:
    bool binSearch(vector<int>& temp, int start, int end, int target){
    	
    	if(start > end){
    		return false;
    	}

    	int index = (end+start) / 2;
    	
    	if(target == temp[index]){
    	    return true;
    	}
    	if(target < temp[index]){
    		return binSearch(temp, start, index-1, target);
    	}
    	else if(target > temp[index]){
    		return binSearch(temp, index+1, end, target);
    	}
    }
};*/


// improvement
// top-right search, time complexity is m+n
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if(m==0){
			return false;
		}        
		int n = matrix[0].size();

		int row = 0; int col = n-1;

		while(row<m && col>=0){
			if(matrix[row][col]==target){
				return true;
			}
			else if(matrix[row][col] > target){
				col --;
			}
			else if(matrix[row][col] < target){
				row ++;
			}
		}
		return false;
    }

};