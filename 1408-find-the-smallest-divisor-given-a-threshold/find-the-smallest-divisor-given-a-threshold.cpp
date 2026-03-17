class Solution {
public:
    bool possible(vector<int>& nums, int m, int k){
        int sum=0;
        for(auto it:nums){
            sum+=(it+m-1)/m;
            if(sum>k)return false;
        }
        return sum<=k;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        // int n=nums.size();
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(possible(nums,m,k)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};