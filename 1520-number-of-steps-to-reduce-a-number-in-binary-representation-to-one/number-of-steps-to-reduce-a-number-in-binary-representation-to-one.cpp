class Solution {
public:
    int numSteps(string s) {
        int end = s.size() - 1;
        int cnt = 0;

        while(end > 0 && s[end] == '0') {
            end--;
            cnt++;
        }

        while(end > 0) {
            while(end >= 0 && s[end] == '1') {
                end--;
                cnt++;
            }

            if(end >= 0) {
                s[end] = '1';
            }
            cnt++;
        }
        return cnt;
    }
};