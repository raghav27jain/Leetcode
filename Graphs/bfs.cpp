vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> bfs;
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for(int n: adj[node]) {
            if(!visited[n]) {
                visited[n] = true;
                q.push(n);
            }
        }
    }
    return bfs; 
}