class Solution {
public:
vector<vector<int>>ans;
void fun(int i,int curr_sum,int k,vector<int>temp,vector<int>num){
    if(i==num.size()){
        if(curr_sum==k)ans.push_back(temp);
        return;
    }
    // if(curr_sum==k){
    //     ans.push_back(temp);
    // }
    if(curr_sum+num[i]<=k){
        temp.push_back(num[i]);
        fun(i,curr_sum+num[i],k,temp,num);
        temp.pop_back();
    }
    fun(i+1,curr_sum,k,temp,num);
}

    vector<vector<int>> combinationSum(vector<int>& num, int k) {
        vector<int>temp;
        fun(0,0,k,temp,num);
        return ans;
    }
};