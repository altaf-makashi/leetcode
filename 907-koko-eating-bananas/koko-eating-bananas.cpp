class Solution {
public:
    bool check(vector<int>& piles, int m,int h){
        long long count=0;
        for(auto it:piles){
            count+=(it+m-1LL)/m;
            if(count>h)return false;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(piles,m,h)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};