class Solution {
public:
    bool possible(vector<int> &arr, int k,int mid){
        int curr=0;
        int count=1,n=arr.size();
        for(int i=0;i<n;i++){
            if(curr+arr[i]<=mid){
                curr+=arr[i];
            }else{
                count++;
                curr=arr[i];
                if(count>k)return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
        if (k > arr.size()) return -1;
        // sort(arr.begin(),arr.end());
        int left=*max_element(arr.begin(),arr.end());
        int right=accumulate(arr.begin(),arr.end(),0);
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(arr,k,mid)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};