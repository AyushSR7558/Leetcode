class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(s.size() < k){
            string p = s;
            reverse(p.begin(), p.end());
            for(int i = 0; i < p.size(); i++) {
                if(p[i] == '0') {
                    p[i] = '1';
                }else {
                    p[i] = '0';
                }
            }
            s = s + '1' + p;
        }
        return s[k - 1];
    }
};