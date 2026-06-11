class Solution {
public:
    void NGE(map<int,int>&mpp,vector<int>&nums2){
        stack<int>st;
        int n=nums2.size();
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty())
                mpp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        int n1=nums1.size();
        vector<int>ans(n1,-1);
        map<int,int>mpp;
        NGE(mpp,nums2);
        for(int i=0;i<n1;i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                ans[i]=mpp[nums1[i]];
            }
        }
        return ans;
    }
};