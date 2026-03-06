class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size() - 1;

        while(n >= 0) {
            if(s[n] != '0') {
                break;
            }
            n--;
        }

        while(n >= 0) {
            if(s[n] != '1') {
                break;
            }
            n--;
        }

        if(n < 0) return true;
        return false;
    }
};