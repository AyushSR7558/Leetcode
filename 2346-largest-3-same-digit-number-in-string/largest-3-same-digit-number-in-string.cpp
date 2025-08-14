class Solution {
public:
    string largestGoodInteger(string nums) {
        unordered_map<char,int> mp;
        string ans = "";
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(i > 2) {
                int prev = --mp[nums[i - 3]];
                if(prev == 0) {
                    mp.erase(nums[i - 3]);
                }
            }
            if(i >= 2 && mp.size() == 1) {
                string temp = "";
                auto ch = mp.begin();
                for(int j = 0; j < 3; j++) {
                    temp += ch -> first;
                }
                if(ans == "" || temp[0] > ans[0]) {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};