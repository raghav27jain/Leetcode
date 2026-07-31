class Solution {
public:
    bool dfs(int node, int final, vector<int> curr[], vector<int>& visited) {
        if (node == final)
            return true;

        visited[node] = 1;

        for (auto neighbor : curr[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, final, curr, visited))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Step 1: Build adjacency list
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Visited array
        vector<int> visited(n, 0);

        // Step 3: DFS
        return dfs(source, destination, adj, visited);
    }
};
