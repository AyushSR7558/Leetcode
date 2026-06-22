class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char, int> freq;

        for(int i = 0; i < n; i++) {
            freq[text[i]]++;
        }

        int minInstance = INT_MAX;
        string s = "balloon";
        for(int i = 0; i < s.size(); i++) {
            minInstance = min(minInstance, (s[i] == 'l'? freq[s[i]] / 2: s[i] == 'o'? freq[s[i]] / 2 : freq[s[i]]));
        }

        return minInstance;
    }
};