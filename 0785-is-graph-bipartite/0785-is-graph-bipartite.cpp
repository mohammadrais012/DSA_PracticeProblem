class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph,vector<int> & vis){
        vis[src]=0;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int x: graph[node]){
                if(vis[x]==-1){
                    vis[x]=!vis[node];
                    q.push(x);
                }
                else if(vis[x]==vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n,-1);

        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!bfs(i,graph,vis)) return false;
            }
        }

        return true;
    }
};