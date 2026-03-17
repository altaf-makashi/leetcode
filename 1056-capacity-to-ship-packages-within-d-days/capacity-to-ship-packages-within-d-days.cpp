class Solution {
public:
    bool possible(vector<int>& nums, int m, int k){
        int days=1,count=0;
        for(auto it:nums){
            if(m<it)return false;
            count+=it;
            if(count>m){
                days++;
                count=0;
                count+=it;
            }
        }
        return days<=k;
    }
    int shipWithinDays(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int total=r;
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if((possible(nums,m,k))){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};