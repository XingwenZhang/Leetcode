// 310. Minimum Height Trees

// For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example 1:

// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3
// return [1]

// Example 2:

// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5
// return [3, 4]

// Note:

// (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

// (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
public:
    // dfs for all nodes, then output all nodes which has min length
    // TLE, need optimize
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        unordered_map<int, int> m; // key for node, val for longest path
        unordered_multimap<int,int> m_edges;

        for(auto item : edges){
            m_edges.insert(item);
            m_edges.insert({item.second, item.first});
        }

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            dfs(i, i, 0, m, m_edges, visited);
            fill(visited.begin(), visited.end(), false);
        }

        int min_path = INT_MAX;

        for(auto item : m){
            if(min_path > item.second){
                min_path = item.second;
                res.clear();
                res.push_back(item.first);
            }
            else if(min_path == item.second){
                res.push_back(item.first);
            }
        }

        return res;

    }

    void dfs(int start, int cur, int path, unordered_map<int,int>& m, unordered_multimap<int,int>& edges, vector<bool>& visited){
        if(visited[cur]) return;
        if(m[start] < path) m[start] = path;

        visited[cur] = true;

        auto range = edges.equal_range(cur);
        for(auto iter = range.first; iter != range.second; iter++){
            dfs(start, iter->second, path+1, m, edges, visited);
        }
    }
};



class Solution {
public:
    // Naive bfs, LTE
    // still need optimize
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        unordered_map<int, int> m; // key for node, val for longest path
        unordered_multimap<int,int> m_edges;

        for(auto item : edges){
            m_edges.insert(item);
            m_edges.insert({item.second, item.first});
        }

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            bfs(i, m, m_edges, visited);
            fill(visited.begin(), visited.end(), false);
        }

        int min_path = INT_MAX;

        for(auto item : m){
            if(min_path > item.second){
                min_path = item.second;
                res.clear();
                res.push_back(item.first);
            }
            else if(min_path == item.second){
                res.push_back(item.first);
            }
        }

        return res;

    }
    void bfs(int start, unordered_map<int,int>& m, unordered_multimap<int,int>& edges, vector<bool>& visited){
        queue<pair<int,int> > q;
        q.push({start, 0});

        while(!q.empty()){
            auto index = q.front();
            visited[index.first] = true;
            if(m[index.first] < index.second) m[index.first] = index.second;
            q.pop();
            auto range = edges.equal_range(index.first);
            for(auto iter = range.first; iter != range.second; iter++){
                if(!visited[iter->second])
                    q.push({iter->second, index.second + 1});
            }
        }
    }
};



class Solution {
public:
    // try multi-end bfs
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        unordered_map<int, int> m; // key for node, val for longest path
        unordered_multimap<int,int> m_edges;

        for(auto item : edges){
            m_edges.insert(item);
            m_edges.insert({item.second, item.first});
        }

        vector<bool> visited(n, false);
        queue<pair<int,int> > q;
        // push multi start points
        for(int node=0; node<n; node++){
            q.push({node, 0});
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            // update the max length of specific start point
            if(m[top.first] < top.second) m[index.first] = index.second;

            auto range = m_edges.equal_range(top.first);
            for(auto iter = range.first; iter != range.second; iter++){
                // if ? 
                q.push({iter->second, top.second + 1});
            }
        }

        int min_path = INT_MAX;

        for(auto item : m){
            if(min_path > item.second){
                min_path = item.second;
                res.clear();
                res.push_back(item.first);
            }
            else if(min_path == item.second){
                res.push_back(item.first);
            }
        }

        return res;

    }
};


class Solution {
public:
    // iteratively delete leave nodes
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return 0;
        vector<int> res;
        vector<unordered_set<int> > adj(n);
        queue<int> q;

        for(auto item : edges){
            adj[item.first].insert(item.second);
            adj[item.second].insert(item.first);
        }

        for(int i=0; i<n; i++){
            // push into all leaves
            if(adj[i].size() == 1) q.push(i);
        }

        while(n > 2){
            int size = q.size();
            n -= size; // remove all leaves
            for(int i=0; i<size(); i++){
                int top = q.front(); q.pop();
                for(auto ele : adj[top]){
                    adj[ele].erase(top);
                    if(adj[ele].size() == 1) q.push(ele);
                }
            }
        }

        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};

