class Solution {
public:
    int n; 
    bool check(vector<int>&nums,int k){
        int minn=0;
        //  point=false;
        for(int i=0;i<n;i+=k){
            bool point=false;
            if(nums[i]<minn)return false;
            int maxx=nums[i];
            for(int j=i+1;j<i+k && j<n;j++){
                
                if(nums[j]<minn)return false;

                if(nums[j]<nums[j-1]){
                    if(point )return false;
                    point=true;
                }
                maxx=max(maxx,nums[j]);
            }
            if (point) {
                if (nums[i] < nums[i + k - 1]) return false;
            }
            minn=maxx;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        n=nums.size();
        int ans=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0)continue;
            if(check(nums,k))
                ans+=k;
        }
        return ans;
    }
};