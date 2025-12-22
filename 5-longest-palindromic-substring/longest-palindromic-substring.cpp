class Solution {
private:
    string OddPalindrome(string s,  int indx){
        int st = indx - 1, ed = indx + 1;
        while(st >= 0 && ed < s.size() && s[st] == s[ed]){
            st--;
            ed++;
        }
        return s.substr(st + 1, ed - st - 1);
    }
    string EvPalindrome(string s,  int indx){
        int st = indx, ed = indx + 1;
        while(st >= 0 && ed < s.size() && s[st] == s[ed]){
            st--;
            ed++;
        }
        if(st == indx){
            return string(1,s[indx]);
        }
        return s.substr(st + 1, ed - st - 1);
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            string odd = OddPalindrome(s,i);
            string even = EvPalindrome(s,i);
            if(ans.size() < odd.size())ans = odd;
            if(ans.size() < even.size())ans = even;
        }
        return ans;
    }
};