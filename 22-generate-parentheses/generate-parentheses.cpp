class Solution {
public:
    bool isValid(string s){
    int balance=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')balance++;
        else balance--;
        if(balance<0)return false;
    }
    return balance==0;
}
void fun(int n,int open,int close,string s,vector<string>&ans){
    if(2*n==s.size()){
        if(isValid(s))ans.push_back(s);
        return;
    }
    if(open<n)fun(n,open+1,close,s+'(',ans);
    if(close<open)fun(n,open,close+1,s+')',ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fun(n,0,0,"",ans);
        return ans;
    }
};