class Solution {
public:
    int n;
    int m;
    
    void dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>&vis,long long &sum ){
        vis[sr][sc]=1;
        sum+=grid[sr][sc];
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        for(int i=0; i<4; i++){
            int nr= sr+dr[i];
            int nc= sc+dc[i];

            if(nr>=0 && nr<n &&nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]){
                dfs(nr,nc,grid,vis,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        long long sum=0 ,cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    dfs(i, j, grid, vis,sum);
                    if(sum%k==0) cnt++;
                    sum=0;
                    
                }
            }
        }

        return cnt;
    }
};