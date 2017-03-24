// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.



class Solution {
public:
	// Binary search
	// 2D matrix converts to 1D

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0){
        	return false;
        }
        int cols = matrix[0].size();
        // If matrix is []
        if(cols == 0){
        	return false;
        }

        int left = 0;
        int right = rows*cols - 1;
        int mid = 0;

        int row = -1;
        int col = -1;
        // Binary search
        while(left <= right){
        	mid = left + (right - left) / 2;
        	row = mid / cols;
        	col = mid % cols;

        	if(matrix[row][col] == target){
        		return true;
        	}

        	if(matrix[row][col] > target){
        		right = mid - 1;
        	}
        	else{
        		left = mid + 1;
        	}
        }

        return false;
    }
};