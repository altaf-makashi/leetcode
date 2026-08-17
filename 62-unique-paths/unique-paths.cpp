class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&memo){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return 1;
        if(memo[i][j]!=-1)return memo[i][j];

        int left=fun(i,j-1,memo);
        int top=fun(i-1,j,memo);

        return memo[i][j]=left+top;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return fun(m-1,n-1,memo);
    }
};