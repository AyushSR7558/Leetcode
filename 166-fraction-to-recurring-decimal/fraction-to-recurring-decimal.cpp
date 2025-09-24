class Solution {
public:
    string fractionToDecimal(int nums, int deno) {
        long long numerator = nums, denominator = deno;

        // Case: numerator is 0
        if (numerator == 0) return "0";

        // Handle sign
        bool needSign = false;
        if (numerator < 0) {
            numerator *= -1;
            needSign = !needSign;
        }
        if (denominator < 0) {
            denominator *= -1;
            needSign = !needSign;
        }

        // Integer part before decimal
        string beforeDot = to_string(numerator / denominator);

        long long temp = (numerator % denominator) * 10;
        if (temp == 0) {
            return (needSign ? "-" + beforeDot : beforeDot);
        }

        // Map to detect repeating remainders
        unordered_map<long long, long long> mp;
        long long recursiveIndx = -1, indx = 0;
        string afterDot = "";

        // Fractional part calculation
        while (temp) {
            if (mp.find(temp) != mp.end()) {
                recursiveIndx = mp[temp];
                break;
            }

            mp[temp] = indx;

            int digit = temp / denominator;
            afterDot += to_string(digit);

            temp = (temp % denominator) * 10;
            indx++;
        }

        // Insert parentheses if repeating cycle detected
        if (recursiveIndx != -1) {
            afterDot.insert(recursiveIndx, "(");
            afterDot.push_back(')');
        }

        // Combine integer part + fractional part
        string ans = beforeDot + "." + afterDot;

        return (needSign ? "-" + ans : ans);
    }
};
