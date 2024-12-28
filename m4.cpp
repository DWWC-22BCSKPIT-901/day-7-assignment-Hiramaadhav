#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

// Function to calculate network delay time
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Build the adjacency list for the graph
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& edge : times) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }

    // Min-heap to store {time, node} pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance array to store the minimum time to each node
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    // Start the Dijkstra's Algorithm
    pq.push({0, k}); // {current_time, starting_node}

    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();

        // If the current time exceeds the recorded time, skip processing
        if (time > dist[node]) continue;

        // Process all neighbors of the current node
        for (const auto& [neighbor, weight] : graph[node]) {
            int newTime = time + weight;

            if (newTime < dist[neighbor]) {
                dist[neighbor] = newTime;
                pq.push({newTime, neighbor});
            }
        }
    }

    // Find the maximum time from the distances
    int maxTime = *max_element(dist.begin() + 1, dist.end());
    return maxTime == INT_MAX ? -1 : maxTime;
}

int main() {
    // Input: times, number of nodes (n), starting node (k)
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int n = 4;
    int k = 2;

    // Compute network delay time
    int result = networkDelayTime(times, n, k);

    // Output the result
    cout << "Network Delay Time: " << result << endl;

    return 0;
}
