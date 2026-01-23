class Solution {
private:
    string toBinary(int num) {
        string s = "";
        while(num) {
            s += (num & 1) + '0';
            num /= 2;
        }
        return s;
    }

    bool isPalindrome(int num) {
        string s = toBinary(num);
        string rev = s;
        reverse(s.begin(), s.end());
        return s == rev;
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> a;

        for(int i = 1; i <= 5000; i++) {
            if(isPalindrome(i)) a.push_back(i);
        }
        vector<int> ans;

        for(int num: nums) {
            int mini = INT_MAX;
            auto it = upper_bound(a.begin(), a.end(), num);
            if(it != a.end()) {
                mini = min(*it - num, mini);
            }
            if(it != a.begin()) {
                mini = min(num - *(it - 1), mini);
            }
            ans.push_back(mini);
        }
        return ans;
    }
};