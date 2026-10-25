class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);

        for(int i=0; i<times.size() ; i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        vector<int> dis(n+1,1e9);
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        dis[k]=0;
        
        while(!pq.empty()){
            auto [dist, node]=pq.top();
            pq.pop();
            
            if(dist> dis[node]) continue;
            
            for(auto it : adj[node]){
                int v = it[0];
                int w = it[1];
                
                if(dis[node]+w< dis[v]){
                    dis[v]=dis[node]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        int time=-1;
        for(int i=1; i<=n; i++){
            time=max(time,dis[i]);
        }
        return time==1e9 ? -1 : time;
    }
};