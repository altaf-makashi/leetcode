class Solution {
public:
    int count_pairs(vector<int>& nums,int low,int mid,int high){
        int cnt=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2LL*nums[j]){
                j++;
            }
            cnt+=j-(mid+1);
        }
        return cnt;
    }
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int>temp;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    int merge_sort(vector<int>& nums,int low,int high){
        int cnt=0;
        if(low>=high)return cnt;
        int mid=low+(high-low)/2;
        cnt+=merge_sort(nums,low,mid);
        cnt+=merge_sort(nums,mid+1,high);
        cnt+=count_pairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size()-1;
        return merge_sort(nums,0,n);
    }
};