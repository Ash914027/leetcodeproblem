class Solution {
public:
    // Helper function to perform DFS and record prerequisites
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, set<pair<int, int>> &s, int start) {
        // Mark the current node as visited
        visited[node] = true;

        // Add the pair (start, node) to the set if `start` is not -1
        // This indicates that `start` is a prerequisite for `node`
        if (start != -1) {
            s.insert({start, node});
        }

        // Explore all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, s, start);
            }
        }
    }

    // Main function to check if prerequisites exist for the given queries
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &pre, vector<vector<int>> &q) {
        // Step 1: Build the adjacency list representation of the graph
        vector<vector<int>> adj(n);
        for (const auto &p : pre) {
            adj[p[0]].push_back(p[1]); // Add a directed edge from p[0] to p[1]
        }

        // Step 2: Use DFS to compute all prerequisites
        set<pair<int, int>> s; // To store all prerequisite pairs (a, b) where a is a prerequisite for b
        for (int i = 0; i < n; i++) {
            // Perform DFS for each node to find all its reachable nodes (prerequisites)
            vector<bool> visited(n, false); // Reset the visited array for each node
            dfs(i, adj, visited, s, i);     // Start DFS from node `i` with `i` as the starting node
        }

        // Step 3: Answer each query based on the set of prerequisites
        vector<bool> result(q.size(), false); // Initialize the result vector with `false`
        for (int i = 0; i < q.size(); i++) {
            // Check if the pair (q[i][0], q[i][1]) exists in the set of prerequisites
            if (s.find({q[i][0], q[i][1]}) != s.end()) {
                result[i] = true; // If found, set the result for this query to `true`
            }
        }

        return result; // Return the result vector
    }
};