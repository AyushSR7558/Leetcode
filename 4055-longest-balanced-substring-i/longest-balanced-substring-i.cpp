class Solution {
public:
    int longestBalanced(string s) {
        int  n = s.size();
        int maxi = 1;
        
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            int maxFreq = 0, val = 0;
            for(int j = i; j < n; j++) {
                freq[s[j]]++;
                if(freq[s[j]] > maxFreq) {
                    val = 1;
                    maxFreq = freq[s[j]];
                }else if(freq[s[j]] == maxFreq) {
                    val++;
                }else {
                    ; // Do Nothing
                }


                if(val == freq.size()) 
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};