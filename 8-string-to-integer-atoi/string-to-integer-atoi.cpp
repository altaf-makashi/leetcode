class Solution {
public:
    int fun(int number,int i,int sign,string &s){
        if(i>=s.size() || !isdigit(s[i]))return number*sign;
        int curr_num=s[i]-'0';
        if(number>(INT_MAX-curr_num)/10){
            return sign==-1?INT_MIN:INT_MAX;
        }
        number=(number*10)+curr_num;
        return fun(number,i+1,sign,s);
    }
    int myAtoi(string s) {
        int i=0;
        int n=s.size(),sign=1;
        while (i < n && s[i] == ' ') {
            i++;
        }

        // ... then process exactly ONE optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        int number=0;
        return fun(number,i,sign,s);
    }
};