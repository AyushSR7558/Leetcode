class Solution {
public:
    int takeCharacters(string s, int k) {
        int n  = s.size();
        int l = 0, r = n - 1;
        unordered_map<char, int> freq;
        
        while(l < n && (freq['a'] < k || freq['b'] < k || freq['c'] < k)) {
            freq[s[l]]++;
            l++;
        }

        if(l == n && (freq['a'] < k || freq['b'] < k || freq['c'] < k)) return -1;
        int Opt = l;
        l--;
        while(l >= 0) {
            freq[s[l]]--;
            while((freq['a'] < k || freq['b'] < k || freq['c'] < k)) {
                freq[s[r]]++;
                r--;
            }
            
            Opt = min(Opt, n - r + l - 1);
            l--;        
        }
        return Opt;
    }
};