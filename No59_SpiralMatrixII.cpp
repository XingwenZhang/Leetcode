// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	// Initial 2D vector
    	int numRow = n;
    	int numCol = n;
    	int initialVal = 0;
    	vector<vector<int> > res;
    	res.resize(numRow, vector<int>(numCol, initialVal));

    	// Spiral fill in matrix
    	// rs: start index of row
    	// re: end index of row
    	// cs: start index of col
    	// ce: end index of col
    	int rs = 0, cs = 0;
    	int re = n, ce = n;
    	int i = 0;
    	int num = 1;
    	while(rs < re && cs < ce){

    		// First row of matrix, direction right
    		for(i = cs; i < ce; i++, num++){
    			res[rs][i] = num;
    		}
    		// Delete this row
    		rs++;

    		// Last col of matrix, direction down
    		for(i = rs; i < re; i++, num++){
    			res[i][ce-1] = num;
    		}
    		// Delete this col
    		ce--;

    		// Last row of matrix, direction left
    		// If judge if exist row
    		if(rs < re){
    			for(i = ce-1; i >= cs; i--, num++){
    				res[re-1][i] = num;
    			}
    		}
    		// Delete this row
    		re--;

    		// First col of matrix, direction up
    		// If judge if exist col
    		if(cs < ce){
    			for(i = re-1; i >= rs; i--, num++){
    				res[i][cs] = num;
    			}
    		}
    		// Delete this col
    		cs++;
    	}

    	return res;
    }
};