/*200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3*/


// union find method
/*class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0){
        	return 0;
        }
        int col = grid[0].size();
        int num = row * col;
        initial(num);
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(grid[i][j]=='1'){
        			// check right

        			if(j!=col-1 && grid[i][j+1]=='1'){
        				myunion(i*col+j, i*col+j+1);
        			}
        			// check down
        			if(i!=row-1 && grid[i+1][j]=='1'){
        				myunion(i*col+j, (i+1)*col+j);
        			}
        		}
        	}
        }
        // for small data, set is quicker than hashset
        unordered_set<int> hashset;
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(grid[i][j]=='1'){
        			hashset.insert(root(i*col+j));
        		}
        	}
        }
        deleteAll();
        return hashset.size();
    }
private:
	// this store the weight of subtree
	int *sz;
	// store the index
	int *id;
	int root(int i){
		while(i != id[i]){
			// path compression, improve one level for node i
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	bool connected(int p, int q){
		return root(p)==root(q);
	}

	void myunion(int p, int q){
		int i = root(p);
		int j = root(q);
		if(i==j){
			return;
		}
		if(sz[i] > sz[j]){
			id[j] = i;
			sz[i] = sz[i] + sz[j];
		}
		else{
			id[i] = j;
			sz[j] = sz[j] + sz[i];
		}
	}
	void initial(int num){
		sz = new int[num];
		id = new int[num];
		for(int i=0; i<num; i++){
			sz[i] = 1;
			id[i] = i;
		}
		

	}
	void deleteAll(){
		delete[] sz;
		delete[] id;
	}

};*/

// still union find, but a little improvement in the final count number of islands

/*class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0){
        	return 0;
        }
        int col = grid[0].size();
        int num = row * col;
        initial(num);
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(grid[i][j]=='1'){
        			// check right

        			if(j!=col-1 && grid[i][j+1]=='1'){
        				myunion(i*col+j, i*col+j+1);
        			}
        			// check down
        			if(i!=row-1 && grid[i+1][j]=='1'){
        				myunion(i*col+j, (i+1)*col+j);
        			}
        		}
        	}
        }

        // if it is the root and the initial position is 1, so it represents an island
        int islands = 0; 
        int i = 0;
        while(i < row*col){
        	if(i==id[i] && grid[i/col][i%col]=='1'){
        		islands ++ ;
        	}
        	i++;
        }
        deleteAll();
        return islands;
    }
private:
	// this store the weight of subtree
	int *sz;
	// store the index
	int *id;
	int root(int i){
		while(i != id[i]){
			// path compression, improve one level for node i
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	bool connected(int p, int q){
		return root(p)==root(q);
	}
	void myunion(int p, int q){
		int i = root(p);
		int j = root(q);
		if(i==j){
			return;
		}
		if(sz[i] > sz[j]){
			id[j] = i;
			sz[i] = sz[i] + sz[j];
		}
		else{
			id[i] = j;
			sz[j] = sz[j] + sz[i];
		}
	}
	void initial(int num){
		sz = new int[num];
		id = new int[num];
		for(int i=0; i<num; i++){
			sz[i] = 1;
			id[i] = i;
		}
	}
	void deleteAll(){
		delete[] sz;
		delete[] id;
	}
};
*/


// actually this is typical searching problem, so the DFS or BFS could be used here.
// DFS recursive

/*class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	int row = grid.size();
    	if(row == 0){
    		return 0;
    	}
    	int col = grid[0].size();
    	int islands = 0;
        vector<vector<bool> > visited(row, vector<bool>(col, false));


        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(!visited[i][j] && grid[i][j] == '1'){
        			islands++;
        			dfs(i,j,visited,grid);
        		}
        	}
        }

        return islands;
    }
private:
	void dfs(int row, int col, vector<vector<bool> >& visited, vector<vector<char> >& grid){
		visited[row][col] = true;
		int m = grid.size(), n = grid[0].size();
		// up search
		if(row - 1 >= 0 && !visited[row-1][col] && grid[row-1][col] == '1'){
			dfs(row - 1, col, visited, grid);
		}
		// down search
		if(row + 1 <= m-1 && !visited[row+1][col] && grid[row+1][col] == '1'){
			dfs(row + 1, col, visited, grid);
		}
		// left search
		if(col - 1 >= 0 && !visited[row][col-1] && grid[row][col-1] == '1'){
			dfs(row, col - 1, visited, grid);
		}
		// right search
		if(col + 1 <= n-1 && !visited[row][col+1] && grid[row][col+1] == '1'){
			dfs(row, col + 1, visited, grid);
		}
	}
};*/


// bfs iterative

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
    	if(row == 0){
    		return 0;
    	}
    	int col = grid[0].size();
    	int islands = 0;
        vector<vector<bool> > visited(row, vector<bool>(col, false));


        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(!visited[i][j] && grid[i][j] == '1'){
        			islands++;
        			bfs(i,j,visited,grid);
        		}
        	}
        }

        return islands;
    }
private:
	void bfs(int row, int col, vector<vector<bool> >& visited, vector<vector<char> >& grid){
		queue<pair<int,int> > q;
		q.push(make_pair(row, col));
		visited[row][col] = true;
		int m = grid.size();
		int n = grid[0].size();
		while(!q.empty()){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			// up search 
			if(r - 1 >= 0 && !visited[r-1][c] && grid[r-1][c] == '1'){
				q.push(make_pair(r-1,c));
				visited[r-1][c] = true;
			}
			// down search
			if(r + 1 <= m-1 && !visited[r+1][c] && grid[r+1][c] == '1'){
				q.push(make_pair(r+1,c));
				visited[r+1][c] = true;
			}
			// left search
					// left search
			if(c - 1 >= 0 && !visited[r][c-1] && grid[r][c-1] == '1'){
				q.push(make_pair(r, c-1));
				visited[r][c-1] = true;
			}
			// right search
			if(c + 1 <= n-1 && !visited[r][c+1] && grid[r][c+1] == '1'){
				q.push(make_pair(r, c+1));
				visited[r][c+1] = true;
			}
		}
	}
};