#ifndef Solution1971_b_hpp
#define Solution1971_b_hpp

#include <stack>
#include <vector>

using std::vector, std::stack;

class Solution1971 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacency_list(n);
        for (vector<int> edge: edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }
        
        stack<int> n_stack;
        n_stack.push(source);
        vector<bool> visited(n);
        
        while (!n_stack.empty()) {
            int node = n_stack.top();
            n_stack.pop();
            
            if (node == destination)
                return true;
            
            if (visited[node])
                continue;
            
            visited[node] = true;
            
            for (int neighbor: adjacency_list[node])
                n_stack.push(neighbor);
        }
        return false;
    }
};

#endif /* Solution1971_b_hpp */
