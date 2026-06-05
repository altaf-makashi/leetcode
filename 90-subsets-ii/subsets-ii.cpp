class Solution {
public:
    void fun(int index,vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums){
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            fun(i+1,ans,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        fun(0,ans,temp,nums);
        return ans;
    }
};