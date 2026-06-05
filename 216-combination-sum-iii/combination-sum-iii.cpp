class Solution {
public:
    vector<vector<int>>ans;
    void fun(int index,int curr_sum,int n,int k,
            vector<int>&temp,vector<int>&nums){
            // base case
            if(k<0 || curr_sum>n)return;
            if(k==0 && curr_sum==n){
                ans.push_back(temp);
                return;
            }
            for(int i=index;i<nums.size();i++){
                temp.push_back(nums[i]);
                fun(i+1,curr_sum+nums[i],n,k-1,temp,nums);
                temp.pop_back();
            }
        }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        fun(0,0,n,k,temp,nums);
        return ans;
    }
};