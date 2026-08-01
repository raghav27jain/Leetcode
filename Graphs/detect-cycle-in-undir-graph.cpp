class Solution {
public:

    bool bfs(int start, vector<int> adj[], vector<bool>& visited)
    {
        queue<pair<int,int>> q;

        q.push({start,-1});

        visited[start]=true;

        while(!q.empty())
        {
            auto current=q.front();
            q.pop();

            int node=current.first;
            int parent=current.second;

            for(auto neighbour:adj[node])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    q.push({neighbour,node});
                }
                else if(neighbour!=parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V,false);

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(bfs(i,adj,visited))
                    return true;
            }
        }

        return false;
    }
};