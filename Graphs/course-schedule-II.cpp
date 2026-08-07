class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto edge : prerequisites)
        {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Queue for courses with indegree 0
        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto neighbour : adj[node])
            {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        // If all courses are completed
        if(ans.size() == numCourses)
        {
            return ans;
        }

        // Cycle exists
        return {};
    }
};