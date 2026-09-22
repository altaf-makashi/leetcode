class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string s="";
        bool flag=false;
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                if(i+1<n && number[i]<number[i+1]){
                    number[i]='$';
                    flag=true;
                }else if(i+1==n){
                    flag=true;
                    number[i]='$';
                }
            }
            if(flag)break;
        }
        if(!flag){
            for(int i=n-1;i>=0;i--){
                if(number[i]==digit){
                    number[i]='$';
                    break;
                }
            }
        }
        string result="";
        for(auto it:number){
            if(it=='$')continue;
            result+=it;
        }
        return result;
    }
};