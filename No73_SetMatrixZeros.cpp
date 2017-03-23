// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    	// Reference: mzchen, link: https://discuss.leetcode.com/topic/5056/any-shorter-o-1-space-solution

    	// Use the first element to store if the corresponding row or col is set to zero
    	// And 0 row and 0 col could conflit, because matrix[0][0] has only one position
    	// so use another variable to store 

    	int rows = matrix.size();
    	int cols = matrix[0].size();
    	int col0 = 1;

    	for(int i = 0; i < rows; i++){

    		// This should be judged at first
    		// not be influenced by the other results
    		if(matrix[i][0] == 0){
    			col0 = 0;
    		} 
    		// col index starts with 1
    		// the first col will be controlled by the col0
    		for(int j = 1; j < cols; j++){
    			if(matrix[i][j] == 0){
    				// This row should be set to 0
    				matrix[i][0] = 0;
    				// This col should be set to 0
    				matrix[0][j] = 0;
    			} 
    		}
    	} 

    	// Avoid the first row and first col
    	// for(int i = 1; i < rows; i++){
    	// 	for(int j = 1; j < cols; j++){
    	// 		if(matrix[i][0] == 0 || matrix[0][j] == 0){
    	// 			matrix[i][j] = 0;
    	// 		}
    	// 	}
    	// 	// This should be judged lastly
    	// 	if(col0 == 0){
    	// 		matrix[i][0] = 0;
    	// 	}
    	// }

    	// This should be traverse by bottom-up
    	// because if do like before, just avoid first row and first col
    	// then the first row cannot be set correctly
    	// for example, [[0,1]]
    	for(int i = rows - 1; i >= 0; i--){
    		for(int j = cols - 1; j >= 1; j--){
    			if(matrix[i][0] == 0 || matrix[0][j] == 0){
    				matrix[i][j] = 0;
    			}
    		}
    		if(col0 == 0){
    			matrix[i][0] = 0;
    		}
    	}

    }
};