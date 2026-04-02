class Solution {
public:

    int recurrsion(int i,int j,vector<vector<int>>& coins,int ability,vector<vector<vector<int>>>&dp){
        // base
        if(i<0 || j<0)return -1e9;
        if (i == 0 && j == 0) {
            if (coins[i][j] < 0 && ability > 0) return 0;
            return coins[i][j];
        }
        if(dp[i][j][ability]!=-1e9)return dp[i][j][ability];
        int left,left_ability,up,up_ability;
        left=left_ability=up=up_ability=-1e9;
        if(coins[i][j]<0 && ability>0){
            left_ability=0+recurrsion(i,j-1,coins,
            ability-1,dp);
            up_ability=0+recurrsion(i-1,j,coins,
            ability-1,dp);
        }
        left=coins[i][j]+recurrsion(i,j-1,coins,ability,dp);
        up=coins[i][j]+recurrsion(i-1,j,coins,ability,dp);

        int up_max=max(up,up_ability);
        int left_max=max(left,left_ability);
        return dp[i][j][ability]=max(up_max,left_max);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size()-1;
        int n=coins[0].size()-1;
        vector<vector<vector<int>>>dp(m+1,
        vector<vector<int>>(n+1,vector<int>(3,-1e9)));
        return recurrsion(m,n,coins,2,dp);
    }
};