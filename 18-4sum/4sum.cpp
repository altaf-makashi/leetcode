class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int left=j+1,right=n-1;
                while(left<right){
                    
                    long long sum=(long long)nums[i]+nums[left]+nums[right]+nums[j];
                    if(sum==target){
                        st.insert({nums[i],nums[j],nums[left],nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    else if(sum>target){
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
        }
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};
