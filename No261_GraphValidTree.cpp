// 261. Graph Valid Tree

// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// For example:

// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

class Solution {
public:

    // Check for if it has cycle and connected graph
    // Method 1, union find
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for(auto& item : edges){
            int x = find(roots, item.first);
            int y = find(roots, item.second);

            if(x == y) return false; // Cycle

            roots[x] = y;
        }

        return edges.size() == n-1; // connected graph
    }

    int find(vector<int> & roots, int index){
        while(roots[index] != -1) index = roots[index];

        return index;
    }
};


class Solution {
public:
    // DFS
    // adj list to store the edges
    // visited to store all visited nodes, check if all nodes are reachable 
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > adj_list(n, vector<int>());

        vector<bool> visited(n, false);

        for(auto& item : edges){
            adj_list[item.first].push_back(item.second);
            adj_list[item.second].push_back(item.first);
        }

        if(!dfs(adj_list, visited, 0, -1)) return false;

        for(auto ele : visited){ // It seems like bool cannot be reference
            if(!ele) return false;
        }

        return true;
    }

    // True for no cycle, false for cycle
    bool dfs(vector<vector<int> >& adj_list, vector<bool>& visited, int cur, int pre){
        if(visited[cur]) return false;
        visited[cur] = true; // set true for visited node
        for(auto& item : adj_list[cur]){
            if(item != pre){
                if(!dfs(adj_list, visited, item, cur)) return false;
            }
        }

        return true;
    }
};



class Solution {
public:
    // BFS
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<set<int> > adj_list(n, set<int>());
        set<int> visited({0});
        queue<int> q({0});

        for(auto& item : edges){
            adj_list[item.first].insert(item.second);
            adj_list[item.second].insert(item.first);
        } 

        while(!q.empty()){
            int t = q.front(); q.pop();

            for(auto& ele : adj_list[t]){
                if(visited.count(ele)) return false;
                visited.insert(ele);
                q.push(ele);
                adj_list[ele].erase(t);
            }
        }

        return visited.size() == n;
    }
};




