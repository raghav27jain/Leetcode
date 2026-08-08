class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        // Build reverse graph
        for(int u = 0; u < n; u++) {

            for(auto v : graph[u]) {

                reverseGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;

        // Terminal nodes
        for(int i = 0; i < n; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        // Kahn's Algorithm
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(auto neighbour : reverseGraph[node]) {

                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};