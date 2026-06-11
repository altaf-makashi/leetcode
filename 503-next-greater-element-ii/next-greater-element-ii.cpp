class Solution {
public:
void NGE(vector<int>&nge,vector<int>&temp){
        stack<int>st;
        int n=temp.size();
        st.push(temp[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=temp[i]){
                st.pop();
            }
            if(!st.empty())
                nge[i]=st.top();
            st.push(temp[i]);
        }
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp=nums;
        for(auto it:nums)temp.push_back(it);
        int m=temp.size();
        vector<int>ans(n,-1);
        vector<int>nge(m,-1);
        NGE(nge,temp);
        for(int i=0;i<n;i++){
            ans[i]=nge[i];
        }
        return ans;
    }
};