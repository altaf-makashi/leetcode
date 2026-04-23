class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>scount;
        unordered_map<char,int>tcount;
        if(s.length()!=t.length())return false;
        for(auto it:s)scount[it]++;
        for(auto it:t)tcount[it]++;
        for(int i=0;i<s.length();i++){
            char chars=s[i];
            char chart=t[i];
            if(scount[chars]!=tcount[chars])return false;
        }
        return true;
    }
};