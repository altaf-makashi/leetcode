class Solution {
public:
int fun(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& memo){
        if(i<0 || j<0)return 1e9;
        if(i==0 && j==0)return grid[0][0];
        if(memo[i][j] !=-1)return memo[i][j];

        int left=grid[i][j]+fun(grid,i,j-1,memo);
        int up=grid[i][j]+fun(grid,i-1,j,memo);

        return memo[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return fun(grid,n-1,m-1,memo);
    }
};