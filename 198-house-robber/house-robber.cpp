class Solution {
public:
    int fun(vector<int>&nums,int i,vector<int>&memo){
        // base case
        if(i<0)return 0;
        if(memo[i]!=-1)return memo[i];

        int pick=nums[i]+fun(nums,i-2,memo);
        int notpick=fun(nums,i-1,memo);

        return memo[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>memo(n,-1);
        return fun(nums,n-1,memo);
    }
};