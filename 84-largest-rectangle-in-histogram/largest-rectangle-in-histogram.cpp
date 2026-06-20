class Solution {
public:
vector<int> getNSE(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> nse(n,n); 
        std::stack<int> st;
        for (int i = n-1; i >=0; i--) {
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
        std::vector<int> pse(n,-1);
        std::stack<int> st;
        for (int i = 0; i < n; ++i) {
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
    int largestRectangleArea(vector<int>& arr) {
        vector<int>nse=getNSE(arr);
        vector<int>pse=getPSE(arr);
        int total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            int curr_area=width*arr[i];
            total=max(total,curr_area);
        }
        return total;
    }
};