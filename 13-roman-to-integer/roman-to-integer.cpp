class Solution {
public:
    int romanToInt(string s) {
        int roman[128];
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // If current value is less than the next value, subtract it
            if (i + 1 < n && roman[s[i]] < roman[s[i+1]]) {
                ans -= roman[s[i]];
            } 
            // Otherwise, add it
            else {
                ans += roman[s[i]];
            }
        }

        return ans;
    }
};