#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    // Result matrix to store distances
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    
    // Queue for BFS
    queue<pair<int, int>> q;
    
    // Initialize the queue with all 0 cells and set their distance to 0
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // Perform BFS
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            
            // Check if the neighboring cell is within bounds and can be updated
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (dist[nr][nc] > dist[r][c] + 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    return dist;
}

int main() {
    // Input matrix
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    
    // Compute distances
    vector<vector<int>> result = updateMatrix(mat);
    
    // Output the result
    cout << "Updated Matrix:" << endl;
    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}
