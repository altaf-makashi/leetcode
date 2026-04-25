class Solution {
public:
    pair<int,int> palindrom(string &s,int i,int j){
        int n=s.size();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return {i+1,j-1};
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0,start=0;
        for(int i=0;i<n;i++){
            auto odd=palindrom(s,i,i);
            auto even=palindrom(s,i,i+1);
            if((odd.second-odd.first+1)>maxlen){
                start=odd.first;
                maxlen=odd.second-odd.first+1;
            }
            if((even.second-even.first+1)>maxlen){
                start=even.first;
                maxlen=even.second-even.first+1;
            }
        }
        return s.substr(start,maxlen);
    }
};