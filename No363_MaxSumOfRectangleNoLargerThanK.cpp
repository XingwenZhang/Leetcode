// 363. Max Sum of Rectangle No Larger Than K

// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

// Example:
// Given matrix = [
//   [1,  0, 1],
//   [0, -2, 3]
// ]
// k = 2
// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

// Note:
// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns?

// TLE还要就是最开始一直数组越界，直到把left right初始化为matrix，以及要最开始判定left, right关系，不能光依靠row1,row2,因为负数的取余操作是不定的。
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = row == 0 ? 0 : matrix[0].size();
        vector<vector<int> > sum_mat(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col; j++){
                sum_mat[i][j] = sum_mat[i-1][j] + sum_mat[i][j-1] - sum_mat[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int n = (row+1)*(col+1);
        vector<vector<int> > cache(n, vector<int>(n, INT_MIN));
        int left = 0;
        int right = row*col-1;
        return sum_util(sum_mat, left, right, cache, k);
    }

    int sum_util(vector<vector<int> >& sum_mat, int left, int right, vector<vector<int> >& cache, int& k){
        if(left > right){
            return INT_MIN;
        }
        int cols = sum_mat[0].size() -1 ;
        int row1 = left / cols;
        int col1 = left % cols;

        int row2 = right / cols;
        int col2 = right % cols;

        if(row1 > row2 || col1 > col2){
            return INT_MIN;
        }

        if(cache[left][right] != INT_MIN){
            return cache[left][right];
        }

        return cache[left][right] = max(max(is_bigger(sum_mat[row2+1][col2+1] - sum_mat[row2+1][col1] - sum_mat[row1][col2+1] + sum_mat[row1][col1],k),
            sum_util(sum_mat, left+1, right, cache, k)), sum_util(sum_mat, left, right-1, cache, k));
    }

    int is_bigger(int sum, int k){
        if(sum > k)
            return INT_MIN;
        else
            return sum;
    }
};


// 2D Kadane's algorithm
// This method has a bug, the reason is that comparison with k cannot be done in main func,
// it should be done in max_util.Because if max is over k, we should discard the res all, 
// we should reserve part of it.
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = row==0?0:matrix[0].size();
        if(row == 0){
            return 0; // seem like 0 is not a good return 
        }
        int max_so_far=INT_MIN, cur_sum=0;
        int max_left=-1, max_right=-1, max_up=-1, max_down=-1;
        int L=0, R=0;
        // Row-wise to implement Kadane's algorithm.
        vector<int> per_col(row, 0); // if the rows >> cols, otherwise per_row(matrix[0].size()). 
        // Time complexity is O(col*col*row), space O(row)
        for(L=0; L<col; L++){
            for(R=L; R<col; R++){
                add_col(row, R, matrix, per_col);
                vector<int> max_vec = max_util(per_col);
                if(max_vec[2] > max_so_far && max_vec[2] <= k){
                    max_so_far = max_vec[2];
                    max_up = max_vec[0];
                    max_down = max_vec[1];
                    max_left = L;
                    max_right = R;
                }
            }
            per_col.assign(per_col.size(), 0);
        }
        return max_so_far;

    }
    void add_col(int row, int col_index, vector<vector<int> >& matrix, vector<int>& per_col){
        for(int i=0; i<row; i++){
            per_col[i] += matrix[i][col_index];
        }
    }
    vector<int> max_util(vector<int>& nums){
        int max_so_far=INT_MIN, sum_here = 0;
        int s=0, start=0, end=0;
        for(int i=0; i<nums.size(); i++){
            sum_here = sum_here + nums[i];
            if(sum_here > max_so_far){
                max_so_far = sum_here;
                start = s;
                end = i;
            }
            if(sum_here < 0){
                sum_here = 0;
                s = i+1; // update start, from next num to the negative sum.
            }
        }
        vector<int> res(3, 0);
        res[0] = start;
        res[1] = end;
        res[2] = max_so_far;
        return res;
    }
};





class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = row==0?0:matrix[0].size();
        if(row == 0){
            return 0; // seem like 0 is not a good return 
        }
        int max_so_far=INT_MIN, cur_sum=0;
        int max_left=-1, max_right=-1, max_up=-1, max_down=-1;
        int L=0, R=0;
        // Row-wise to implement Kadane's algorithm.
        vector<int> per_col(row, 0); // if the rows >> cols, otherwise per_row(matrix[0].size()). 
        // Time complexity is O(col*col*row), space O(row)
        for(L=0; L<col; L++){
            for(R=L; R<col; R++){
                add_col(row, R, matrix, per_col);
                // vector<int> max_vec = max_util(per_col);
                cur_sum = max_util_no_lager_than_K(per_col, k);
                if(cur_sum > max_so_far){
                    max_so_far = cur_sum;
                }
            }
            per_col.assign(per_col.size(), 0);
        }
        return max_so_far;

    }
    void add_col(int row, int col_index, vector<vector<int> >& matrix, vector<int>& per_col){
        for(int i=0; i<row; i++){
            per_col[i] += matrix[i][col_index];
        }
    }
    int max_util_no_lager_than_K(vector<int>& nums, int k){
        set<int> s;
        s.insert(0);
        int max_res = 0;
        int cur_sum=0;
        for(auto& i: nums){
            cur_sum += i;
            auto it = s.lower_bound(cur_sum-k);
            // start = it, end = i.index
            if(it != s.end()) max_res = max(max_res, cur_sum-*it);
            s.insert(cur_sum);
        } 
        return max_res;
    }
};

