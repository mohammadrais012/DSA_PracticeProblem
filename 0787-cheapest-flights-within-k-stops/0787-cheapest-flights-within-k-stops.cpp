class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        //{node,{cost,stops}}

        vector<int> dist(n,1e9);
        q.push({src,{0,-1}});
        dist[src]=0;

        while(!q.empty()){
            int node = q.front().first;
            int cost= q.front().second.first;
            int stops= q.front().second.second;

            q.pop();

            if(stops>k) continue;

            for( auto it : adj[node]){
                int adjNode=it.first;
                int wt= it.second;

                if(cost+wt<dist[adjNode]  && stops<k){
                    dist[adjNode]= cost+wt;

                    q.push({adjNode,{dist[adjNode],stops+1}});
                }
            }

           
        }
         return dist[dst]==1e9 ? -1 : dist[dst];
    }
};