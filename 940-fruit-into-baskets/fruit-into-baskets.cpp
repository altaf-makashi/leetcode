class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        int l=0,r=0,max_len=0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0)mpp.erase(nums[l]);
                l++;
            }
            max_len=max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};