class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> count;
        vector<unordered_map<char, int>> mp(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                mp[i][words[i][j]]++;
            }
        }
        count.push_back(words[0]);
        for(int i = 1; i < n; i++) {
            bool isAnagram = true;
            if(mp[i - 1].size() == mp[i].size()) {
                for(auto x : mp[i]){
                    if(x.second != mp[i - 1][x.first]) {
                        isAnagram = false;
                        break;
                    }
                }
            }else {
                isAnagram = false;
            }
            if(!isAnagram) {
                count.push_back(words[i]);
            }
        }
        return count;
    }
};