class Solution {
public :
    void PGE(vector<int>&pge,vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pge[i]=st.top();
            }
            if (st.empty()) {
                st.push(nums[i]);
            } else if (nums[i] < st.top()) {
                // We only care about tracking the largest boundaries
                st.push(st.top()); 
            }
        }
    }
    void NGE(vector<int>&nge,vector<int>&nums){
        stack<int>st;
        int n=nums.size();
        st.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(!st.empty())
                nge[i]=st.top();
            if (st.empty()) {
                st.push(nums[i]);
            } else if (nums[i] < st.top()) {
                // We only care about tracking the largest boundaries
                st.push(st.top()); 
            }
        }
    }
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>pge(n,-1),nge(n,-1);
        PGE(pge,nums);
        NGE(nge,nums);
        int ans=0;
        for(int i=0;i<n;i++){
            if(pge[i]!=-1 && nge[i]!=-1){
                int min_height=min(pge[i],nge[i]);
                ans+=(min_height-nums[i]);
            }
        }
        return ans;
    }
};