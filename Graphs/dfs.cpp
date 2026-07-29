class Solution {
    public:
        void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<in>& ans) {
            visited[node] = true;
            ans.push_back(node);
            for(int neigh: adj[node]) {
                if(!visited[neigh]) {
                    dfs(node, adj, visited, ans);
                }
            }
        }

        vector<int> dfsOfGraph(int v, vector<vector<int>>& adj) {
            vector<bool> visited(v, false);
            vector<int> ans;
            dfs(0, adj, visited, ans);
            return ans;
        }
};