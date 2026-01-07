class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        int n = tasks.size();

        for(int i = 0; i < n; i++) {
            freq[tasks[i]]++;
        }

        int output = 0;
        for(auto num : freq) {
            int x = num.second;
            if(x == 1) return -1;

            if(x % 3 == 0) {
                output += x / 3;
            }else {
                output += x / 3 + 1;
            }
        }

        return output;

    }
};