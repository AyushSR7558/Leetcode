class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr_len = 0, prev_len = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                if(curr_len != 0){
                    prev_len = curr_len;
                    curr_len = 0;
                }
            }else {
                curr_len++;
            }
        }
        cout << curr_len << " " << prev_len;
        return (curr_len == 0? prev_len: curr_len);
    }
};