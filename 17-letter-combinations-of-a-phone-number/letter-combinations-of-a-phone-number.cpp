class Solution {
public:
    vector<string>ans;
    void fun(int index,string &temp,vector<string> &keypad,string &digits){
        // base case 
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        int num=digits[index]-'0';
        string curr_str=keypad[num];
        for(int i=0;i<curr_str.size();i++){
            temp+=curr_str[i];
            fun(index+1,temp,keypad,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>keypad = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string temp="";
        fun(0,temp,keypad,digits);
        return ans;
    }
};