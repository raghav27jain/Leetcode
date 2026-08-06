class Solution {
public:

    bool dfs(int node, int parent, vector<int> adj[],
             vector<bool>& visited)
    {
        visited[node] = true;

        for(auto neighbour : adj[node])
        {
            // If neighbour is not visited, explore it
            if(!visited[neighbour])
            {
                if(dfs(neighbour, node, adj, visited))
                    return true;
            }

            // If neighbour is visited and is NOT the parent
            else if(neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        // Step 1: Convert edge list to adjacency list
        vector<int> adj[V];

        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Visited array
        vector<bool> visited(V, false);

        // Step 3: Run DFS for every component
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};