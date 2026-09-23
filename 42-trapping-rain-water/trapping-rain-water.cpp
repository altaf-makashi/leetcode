class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size(),ans=0;
        int l=0,r=n-1;
        int lmax=nums[l],rmax=nums[r];
        while(l<r){
            if(nums[l]<nums[r]){
                if(nums[l]<lmax){
                    ans+=lmax-nums[l];
                }else{
                    lmax=nums[l];
                }
                l++;
            }else{
                if(nums[r]<rmax){
                    ans+=rmax-nums[r];
                }else{
                    rmax=nums[r];
                }
                r--;
            }
        }
        return ans;
    }
};