class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);

        for(int i=0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<double>dis(n,-1);
        priority_queue<pair<double,int>> pq;

        pq.push({1,start});
        dis[start]=1;

        while(!pq.empty()){
            auto [dist,node]= pq.top();
            pq.pop();

            if(dist< dis[node]) continue;

            for(auto it : adj[node]){
                int v = it.first;
                double w = it.second;

                if(dis[node]*w > dis[v]){
                    dis[v]=dis[node]*w;
                    pq.push({dis[v],v});
                }
            }

        }
        return dis[end] == -1? 0: dis[end];

    }
};