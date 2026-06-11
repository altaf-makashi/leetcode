class Solution {
public :
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>pge(n),nge(n);
        pge[0]=nums[0];
        for(int i=1;i<n;i++){
            pge[i]=max(pge[i-1],nums[i]);
        }
        nge[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            nge[i]=max(nge[i+1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pge[i]!=-1 && nge[i]!=-1)
                ans+=min(pge[i],nge[i])-nums[i];
        }
        return ans;
    }
};