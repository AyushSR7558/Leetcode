class Solution {
private:
    string to_binary(int n, int sz) {
        string s;
        while(n) {
            s += ((n & 1) + '0');
            n /= 2;
        }

        while(s.size() < sz) {
            s += '0';
        }
        reverse(s.begin(), s.end());
        return s;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size(), k = nums.size();
        unordered_set<string> st;

        for(int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }
        int x = (1 << n);

        for(int i = 0; i < x; i++) {
            string temp = to_binary(i, n);
            if(!st.count(temp)) {
                return temp;
            }
        }
        return "";
    }
};