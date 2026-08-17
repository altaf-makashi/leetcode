class Solution {
public:
    int fun(vector<int>& nums) {
        int n=nums.size();
        vector<int>memo(n,0);
        if(n<=1)return nums[0];
        memo[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)pick+=memo[i-2];
            int notpick=memo[i-1];
            memo[i]=max(pick,notpick);
        }
        return memo[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return nums[0];
        int ft=nums[0];
        nums[0]=0;
        int eleFirst=fun(nums);
        nums[0]=ft;
        nums[n-1]=0;
        int eleLast=fun(nums);
        return max(eleFirst,eleLast);
    }
};