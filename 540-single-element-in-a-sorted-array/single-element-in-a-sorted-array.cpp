class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int left=0;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid==0 && nums[mid]!=nums[mid+1])return nums[mid];
            else if(mid==n-1 && nums[mid]!=nums[mid-1])
                return nums[mid];
            else if(mid>0 && mid<n && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            if(mid<n && nums[mid]==nums[mid+1])mid++;
            if((mid-left+1)%2!=0){
                right=mid-1;
                
            }else{
                left=mid+1;
            }
        }
        return -1;
    }
};