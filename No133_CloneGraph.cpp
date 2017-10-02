// 133. Clone Graph

// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


// OJ's undirected graph serialization:
// Nodes are labeled uniquely.

// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
// Visually, the graph looks like the following:

//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// Key point is: no need to create the same node twice
#define Node UndirectedGraphNode
#define um unordered_map<int, Node*> 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        um hash_map;
        return clone_util(node, hash_map);
    }

    Node* clone_util(Node* node, um& hash_map){
        if(node == nullptr) return node;
        if(hash_map.count(node->label)) return hash_map[node->label];

        Node* new_node = new Node(node->label); // create new node
        hash_map[new_node->label] = new_node; // store into map
        for(auto i : node->neighbors){
            new_node->neighbors.push_back(clone_util(i, hash_map));
        }

        return new_node;
    }
};