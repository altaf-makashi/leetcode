class Solution {
public:
    vector<vector<int>>ans;
    void helper(int index,int curr_sum,vector<int>&temp,vector<int>&nums,int target){
        if(curr_sum>target || index>=nums.size())return;
        if(curr_sum==target){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(index,curr_sum+nums[index],temp,nums,target);
        temp.pop_back();
        helper(index+1,curr_sum,temp,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        helper(0,0,temp,nums,target);
        return ans;
    }
};