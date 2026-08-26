class Solution {
public:
    int helper(vector<int>&coins,int amount,int i,vector<vector<int>>&memo){
        // base case
        if(amount==0)return 0;
        if(i<0)return 1e9;
        if(memo[i][amount]!=-1)return memo[i][amount];

        int pick=1e9;
        if(coins[i]<=amount){
            pick=1+helper(coins,amount-coins[i],i,memo);
        }
        int notpick=helper(coins,amount,i-1,memo);

        return memo[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>memo(n+1,vector<int>(amount+1,-1));
        int ans= helper(coins,amount,n-1,memo);
        return ans!=1e9 ? ans : -1 ;
    }
};