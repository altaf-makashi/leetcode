class Solution {
public:
    vector<vector<int>>ans;
    void helper(int index,int curr_sum,vector<int>&temp,vector<int>&nums,int target){
        if(curr_sum==target){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(curr_sum>target){
                return ;
            }
            if(i>index && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            helper(i+1,curr_sum+nums[i],temp,nums,target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        helper(0,0,temp,nums,target);
        return ans;
    }
};