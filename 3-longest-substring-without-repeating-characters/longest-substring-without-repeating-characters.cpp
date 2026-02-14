class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // If there is the problem of the substring we can think of the sliding window algorithm
        int l = 0, maxi = 0;
        unordered_set<char> st;

        for(int i = 0; i < n; i++) {
            while(st.count(s[i])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            maxi = max(i - l + 1, maxi);
        }
        return maxi;
    }
};