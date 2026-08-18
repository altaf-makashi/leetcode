class Solution {
public:
    bool fun(vector<int>&nums,int sum,int curr,int i,vector<vector<int>>&memo){
        if(sum==curr)return true;
        if(i==0)return sum==(curr+nums[i]);
        if(memo[i][curr]!=-1)return memo[i][curr];
        // base case

        bool pick=false;
        if(curr+nums[i]<=sum)
            pick=fun(nums,sum,curr+nums[i],i-1,memo);
        bool notpick=fun(nums,sum,curr,i-1,memo);

        return memo[i][curr]=pick||notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        sum/=2;
        int n=nums.size();
        vector<vector<int>>memo(n,vector<int>(sum,-1));
        return fun(nums,sum,0,n-1,memo);
    }
};