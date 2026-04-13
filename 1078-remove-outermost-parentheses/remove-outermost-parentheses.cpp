class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(auto it:s){
            if(cnt==0){
                cnt++;
                continue;
            }else{
                if(it=='('){
                    cnt++;
                    ans+=it;
                }else if(it==')' && cnt>1){
                    ans+=it;
                    cnt--;
                }else{
                    cnt--;
                }
            }
        }
        return ans;
    }
};