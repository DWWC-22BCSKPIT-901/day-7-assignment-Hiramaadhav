#include <iostream>
#include <vector>
using namespace std;

// Helper function for DFS
void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
    // Add the current node to the path
    path.push_back(node);

    // If we reach the target node, add the path to the result
    if (node == graph.size() - 1) {
        result.push_back(path);
    } else {
        // Recur for all neighbors of the current node
        for (int neighbor : graph[node]) {
            dfs(neighbor, graph, path, result);
        }
    }

    // Backtrack by removing the current node from the path
    path.pop_back();
}

// Function to find all paths from source to target
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(0, graph, path, result);
    return result;
}

int main() {
    // Input graph
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    // Find all paths
    vector<vector<int>> paths = allPathsSourceTarget(graph);

    // Output the result
    cout << "All Paths From Source to Target:" << endl;
    for (const auto& path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
