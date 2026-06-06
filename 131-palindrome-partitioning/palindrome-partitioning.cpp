class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrom(string temp){
        int l=0,r=temp.size()-1;
        while(l<=r){
            if(temp[l]!=temp[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void fun(int index,vector<string>&temp,string &s){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            string sub=s.substr(index,i-index+1);
            if(isPalindrom(sub)){
                temp.push_back(sub);
                fun(i+1,temp,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        fun(0,temp,s);
        return ans;
    }
};