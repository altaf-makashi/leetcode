class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int n=nums.size();
        int max_sum=-1e9;
        int sum=0;
        for(auto it:nums){
            sum+=it;
            max_sum=max(max_sum,sum);
            if(sum<0)sum=0;
        }
        return max_sum;
    }
};