#include <iostream>
#include "Solution1971-b.hpp"

void displayAdjList(vector<vector<int>>& adj_list, int v) {
    for (int i = 0; i < v; ++i) {
        std::cout << i << " -> ";
        for (auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            if (it + 1 != adj_list[i].end()) {
                std::cout << *it << " -> ";
            } else {
                std::cout << *it << std::endl;
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj_list, int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

int main() {
    vector<vector<int>> adj_list(3);
    
    addEdge(adj_list, 0, 1);
    addEdge(adj_list, 1, 2);
    addEdge(adj_list, 2, 0);
    
    displayAdjList(adj_list, 3);
    
    Solution1971 test;
    bool result = test.validPath(3, adj_list, 0, 3);
    
    std::cout << std::boolalpha;
    std::cout << "result: " << result << std::endl;
    return 0;
}
