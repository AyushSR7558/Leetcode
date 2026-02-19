class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int p = 0, q = 0, cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                if(i > 0 && s[i] != s[i - 1]) p = 0;
                p++;
                if(q >= p) cnt++;
            }else {
                if(i > 0 && s[i] != s[i - 1]) q = 0;
                q++;
                if(p >= q) cnt++;
            }
        }
        return cnt;
    }
};