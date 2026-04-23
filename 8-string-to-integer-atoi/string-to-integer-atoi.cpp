class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0; // Use long to detect overflow easily
        int sign = 1;

        // 1. Skip whitespace
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before updating result
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(result * sign);
    }
};