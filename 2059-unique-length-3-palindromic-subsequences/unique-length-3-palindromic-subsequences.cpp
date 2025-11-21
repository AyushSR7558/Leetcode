class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> freqL, freqR;
        unordered_set<string> st;

        for(char ch : s) {
            freqR[ch]++;
        }

        for(int i = 0; i < s.size(); i++) {
            freqR[s[i]]--;
            if(freqR[s[i]] == 0) freqR.erase(s[i]);

            for(auto a : freqL) {
                if(freqR.count(a.first)) {
                    st.insert(( string() + a.first + s[i] + a.first));
                }
            }

            freqL[s[i]]++;
        }
        return st.size();
    }
};