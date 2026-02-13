class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size(); // Size of the words
        int m = allowed.size(); // Size of the allowed
        int cnt = 0; // Count the number of the consistent strings

        unordered_set<char> st;

        for(int i = 0; i < m; i++) {
            st.insert(allowed[i]);
        }

        for(int i = 0; i < n; i++) {
            unordered_set<char> temp;
            bool inc = true;

            for(int j = 0; j < words[i].size(); j++) {
                temp.insert(words[i][j]);
            }

            for(char ch : temp) {
                if(!st.count(ch)){
                    inc = false;
                    break;
                }
            }

            if(inc) cnt++;
        }
        return cnt;
    }
};