class Solution {
public:
    int count(vector<int>&freq){
        int maxx=0,minn=1e5;
        for(auto it:freq){
            if(it!=0)
            minn=min(it,minn);
            maxx=max(maxx,it);
        }
        if(minn==1e5 || maxx==0)return 0;
        return maxx-minn;
    }
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(j-i>1)
                    ans+=count(freq);
            }
        }
        return ans;
    }
};