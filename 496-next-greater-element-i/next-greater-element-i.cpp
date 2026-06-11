class Solution {
public:
    void NGE(vector<int>&nge,vector<int>&nums2){
        stack<int>st;
        int n=nums2.size();
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty())
                nge[i]=st.top();
            st.push(nums2[i]);
        }
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        int n1=nums1.size();
        vector<int>nge(n2,-1),ans(n1,-1);
        NGE(nge,nums2);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=nge[j];
                    break;
                }
            }
        }
        return ans;
    }
};