#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the center of the star graph
int findCenter(vector<vector<int>>& edges) {
    // Count the degree of each node
    unordered_map<int, int> degree;
    for (auto& edge : edges) {
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    // The center node will have the highest degree
    for (auto& [node, deg] : degree) {
        if (deg == edges.size()) { // The center connects to all other nodes
            return node;
        }
    }
    return -1; // This case shouldn't happen in a valid star graph
}

int main() {
    // Example input for a star graph
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}};

    // Find the center
    int center = findCenter(edges);

    // Output the result
    cout << "The center of the star graph is: " << center << endl;

    return 0;
}
