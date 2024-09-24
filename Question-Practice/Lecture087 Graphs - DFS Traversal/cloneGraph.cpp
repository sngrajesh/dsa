// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node, std::unordered_map<Node*, Node*>& clonedNodes) {
        if (!node) return NULL;
        
        if (clonedNodes.find(node) != clonedNodes.end()) {
            return clonedNodes[node];
        }
        
        Node* clone = new Node(node->val);
        clonedNodes[node] = clone; 
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(solve(neighbor, clonedNodes));
        }
        
        return clone;
    }

    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> clonedNodes;
        return solve(node, clonedNodes);
    }
};
