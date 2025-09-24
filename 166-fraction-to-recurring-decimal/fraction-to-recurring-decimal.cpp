class Solution {
public:
    string fractionToDecimal(int nums, int deno) {
        long long numerator = nums, denominator = deno;
        if(numerator ==0) return "0";
        bool needSign = false;
        if(numerator < 0) {
            numerator *= -1;
            needSign = !needSign;
        }
        if(denominator < 0) {
            denominator *= -1;
            needSign = !needSign;
        }
        string beforeDot = "";
        beforeDot += to_string(numerator / denominator);
        long long temp = numerator % denominator * 10;
        if(temp == 0) return (needSign? '-' + beforeDot: beforeDot);
        unordered_map<long long, long long> mp;
        long long recursiveIndx = -1, indx = 0;
        string afterDot = "";
        while(temp) {
            int digit = 0;
            if(mp.find(temp) != mp.end()) {
                recursiveIndx = mp[temp];
                break;
            }
            mp[temp] = indx;
            if(temp > denominator) {
                digit = temp / denominator;
                temp = temp % denominator;
            }
            temp *= 10; 
            afterDot += to_string(digit);
            indx++;
        }
        cout << recursiveIndx;
        if(recursiveIndx != -1)
        {afterDot.insert(recursiveIndx, "(");
        afterDot.push_back(')');}
        string ans = beforeDot + '.' + afterDot;
        return (needSign? '-' + ans: ans);
    }
};