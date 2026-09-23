class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int>dq;
        vector<int>res;
        int n=arr.size();
        int i=0;
        while(i<n){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)res.push_back(arr[dq.front()]);
            i++;
        }
        return res;
    }
};