class Solution {
public:
    int fun(int amt,vector<int>& coins,int ind,vector<vector<int>>&dp){
        // base case
        if(ind<0 || amt<0)return 0;
        if(amt==0)return 1;
        if(dp[amt][ind]!=-1)return dp[amt][ind];
        int pick=fun(amt-coins[ind],coins,ind,dp);
        int notpick=fun(amt,coins,ind-1,dp);

        return dp[amt][ind]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        return fun(amount,coins,n-1,dp);
    }
};