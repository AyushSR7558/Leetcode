class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>mp;
        long long temp = 1;
        mp.insert("1");
        while(temp <= n * 10LL) {
            string st = to_string(temp);
            sort(st.begin(),st.end());
            mp.insert(st);
            temp = temp << 1;
        }
        string stringN = to_string(n);
        sort(stringN.begin(),stringN.end());
        return (mp.find(stringN) != mp.end() ? true: false);
    }
};