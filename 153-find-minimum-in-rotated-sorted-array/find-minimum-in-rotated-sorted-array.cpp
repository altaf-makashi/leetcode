class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=1e4;
        int left=0,n=nums.size()-1;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            // if(nums[mid]==target)return mid;
            if(nums[left]<=nums[mid]){
                ans=min(ans,nums[left]);
                left=mid+1;
            }else{
                ans=min(ans,nums[mid]);
                right=mid-1;
            }
        }
        return ans;
    }
};