class Solution {
public:
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        int edgeSize = edges.size();
        for (int i = 0; i < edgeSize; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<bool> vis(n + 1, false);
        queue<int> q;
        vis[source] = true;
        q.push(source);
        
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for (auto x : adj[temp])
            {
                if (vis[x] == false)
                {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        return vis[destination];
        
    }
};