class Solution {
private:
    unordered_set<string> makeList(string s) {
        unordered_set<string> mp;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j <= s.size(); j++) {
                mp.insert(s.substr(i, j - i + 1));
            }
        }
        return mp;
    }
    
    string toBinary(int n) {
        string temp;
        while(n) {
            temp += ((n & 1) + '0');
            n /= 2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
public:
    bool queryString(string s, int n) {
        unordered_set<string> mp = makeList(s);

        for(int i = 1; i <= n; i++) {
            if(!mp.count(toBinary(i))) return false;
        }
        return true;
    }
};