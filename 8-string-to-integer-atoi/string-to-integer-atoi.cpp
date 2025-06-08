class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // Step 1: Skip whitespaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Check sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Step 3: Parse digits
        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            // Step 4: Clamp if out of bounds
            if (sign * num <= INT_MIN) return INT_MIN;
            if (sign * num >= INT_MAX) return INT_MAX;
            i++;
        }

        return (int)(sign * num);
    }
};
