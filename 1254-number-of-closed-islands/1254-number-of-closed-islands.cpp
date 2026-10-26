class Solution {
public:
    int n , m;
    bool dfs(int sr, int sc, vector<vector<int>>& grid){
        if(sr<0 || sr>=n || sc<0 || sc>=m ) return false;
        if(grid[sr][sc]==1) return true;

        grid[sr][sc]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        bool ans= true;
        for(int i=0; i<4; i++){
            int nr= sr+dr[i];
            int nc= sc+dc[i];
            ans &=  dfs(nr,nc,grid);
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
       n = grid.size();
       m = grid[0].size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid)) cnt++;
                }
            }
        }

        return cnt;
    }
};