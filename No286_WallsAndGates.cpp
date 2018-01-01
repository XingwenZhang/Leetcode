// 286. Walls and Gates

// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

// For example, given the 2D grid:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// After running your function, the 2D grid should be:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4

class Solution {
public:
    // dfs to update, start from gate to all reachable rooms
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    // visited[i][j] = true;
                    dfs(rooms, i, j);
                }
            }
        }
    }

    void dfs(vector<vector<int> >& rooms,int index_x, int index_y){
        int prev_val = rooms[idx][idy];
        for(int i=0; i<4; i++){
            int idx = index_x + x[i];
            int idy = index_y + y[i];
            if(idx < rooms.size() && idx >= 0 && idy < rooms[0].size() && idy >= 0 && rooms[idx][idy] > prev_val + 1){
                rooms[idx][idy] = prev_val + 1;
                dfs(rooms, visited, idx, idy);
                
            }
        }
    }
private:
    const int x[4] = {0, 0, -1, 1};
    const int y[4] = {1, -1, 0, 0};
};


// BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    bfs(rooms, i, j);
                }
            }
        }
    }

    void bfs(vector<vector<int> >& rooms, int i, int j){
        int m = rooms.size(), n = rooms[0].size();

        queue<pair<int,int> > q;

        q.push({i, j});

        while(!q.empty()){
            auto top = q.front(); q.pop();
            for(int k=0; k<4; k++){
                int x = d[k] + top.first;
                int y = d[k+1] + top.second;
                if(x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] > rooms[top.first][top.second] + 1){
                    rooms[x][y] = rooms[top.first][top.second] + 1;
                    q.push({x,y});
                }
            }
        }
    }
private:
    int d[5] = {0, 1, 0, -1, 0};
};


// Multi-End BFS, O(MN)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int> > q;
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    // Store all gates
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto top = q.front(); q.pop();
            for(int k=0; k<4; k++){
                int x = d[k] + top.first;
                int y = d[k+1] + top.second;

                if(x >= 0 && x <rooms.size() && y >= 0 && y < rooms[0].size() && rooms[x][y] > rooms[top.first][top.second] + 1){
                    rooms[x][y] = rooms[top.first][top.second] + 1;
                    q.push({x,y});
                }
            }
        }
    }
private:
    int d[5] = {0, 1, 0, -1, 0};
};

