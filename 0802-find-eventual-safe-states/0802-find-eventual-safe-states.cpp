class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> adj[n];
        vector<int> indeg(n,0);
        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
               int v = graph[i][j];
               indeg[i]++;
               adj[v].push_back(i);
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto v : adj[node]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};