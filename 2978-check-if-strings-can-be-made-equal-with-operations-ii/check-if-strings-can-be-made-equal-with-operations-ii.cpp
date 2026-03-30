class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<char, int> oddFreq,  evenFreq;

        for(int i = 0; i < n; i++) {
            if(i & 1) {
                oddFreq[s1[i]]++;
            }else {
                evenFreq[s1[i]]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i & 1) {
                if(!oddFreq.count(s2[i])) return false;
                oddFreq[s2[i]]--;
                if(oddFreq[s2[i]] == 0) oddFreq.erase(s2[i]);
            }else {
                if(!evenFreq.count(s2[i])) return false;
                evenFreq[s2[i]]--;
                if(evenFreq[s2[i]] == 0) evenFreq.erase(s2[i]);
            }
        }

        return true;
    }
};