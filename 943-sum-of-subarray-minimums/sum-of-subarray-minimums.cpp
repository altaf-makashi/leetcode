class Solution {
public:
    vector<int> getNSE(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> nse(n,n); // Default to 'n' if no smaller element exists
        std::stack<int> st;
        for (int i = n-1; i >=0; i--) {
            // While current element is smaller than the element at the stack's top
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nse[i]=!st.empty()?st.top():n;
            st.push(i);
        }
        return nse;
    }
    vector<int> getPSE(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> pse(n,-1); // Default to '-1' if no smaller element exists
        std::stack<int> st;

        for (int i = 0; i < n; ++i) {
            // Pop elements that are greater than or equal to the current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=getNSE(arr);
        vector<int>pse=getPSE(arr);
        int total=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            long long left_count = i - pse[i];
            long long right_count = nse[i] - i;
            
            long long contribution = (left_count * right_count) % mod;
            contribution = (contribution * arr[i]) % mod;
            
            total = (total + contribution) % mod;
        }
        return total;
    }
};