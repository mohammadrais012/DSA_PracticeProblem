class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
         int n = prerequisites.size();
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);
        for(int i=0; i<n; i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            indeg[v]++;
            adj[u].push_back(v);

        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> result;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(int v : adj[node]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        if(result.size()!=V) return {};
        return result;
        
    }
};