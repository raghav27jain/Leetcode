class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

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

        queue<int> q;

        // Push all courses having indegree 0
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            completed++;

            for(auto neighbour : adj[node])
            {
                indegree[neighbour]--;

                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return completed == numCourses;
    }
};