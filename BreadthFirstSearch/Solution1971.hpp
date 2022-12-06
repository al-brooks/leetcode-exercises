#ifndef Solution1971_hpp
#define Solution1971_hpp

#include <vector>
#include <queue>

using std::vector, std::queue;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge: edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        queue<int> node_queue;
        node_queue.push(source);
        vector<bool> visited(n);
        visited[source] = true;
        
        while (!node_queue.empty()) {
            int node = node_queue.front();
            node_queue.pop();
            
            if (node == destination) {
                return true;
            }
            
            vector<int> neighbors = adjacency_list[node];
            
            for (int neighbor: neighbors) {
                if (!visited[neighbor]) {
                    node_queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return false;
    }
};

#endif /* Solution1971_hpp */
