class Solution {
private:
    bool helper(string s1, const string s2, unordered_map<string,bool>& mp) {
        int n = s2.size();
        string key = s1+"_" +s2;
        if(mp.find(key) != mp.end()) return mp[key];
        if(s1.size() != s2.size()) return false;
        string t1 = s1;
        string t2 = s2;
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        if(t1 != t2) return false;
        // We can make spilt from i = 1 to i = n - 1
        // This can be done using the for loop
        if (s1 == s2)
            return true;
        bool canScramble = false;
        for (int i = 1; i < n; i++) {
            string splitString1 = s1.substr(0, i);
            string splitString2 = s1.substr(i);
            // Either we can swap or we cannot swap we ll make the bool
            // according to it
            canScramble = ((helper(splitString1, s2.substr(0, i), mp) &&
                                 helper(splitString2, s2.substr(i),mp)) ||
                                ((helper(splitString1, s2.substr(n - i), mp) &&
                                  helper(splitString2, s2.substr(0, n - i), mp))));

            if(canScramble == true) break;
        }
        return mp[key] = canScramble;
    }

public:
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> mp;
        return helper(s2,s1,mp);
    }
};