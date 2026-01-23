class Solution {
private:
    string toBinary(int num) {
        string s = "";
        while(num) {
            s += (num & 1) + '0'; 
            num /= 2;
        }
        return s;
    }

    int reflection(int num) {
        string s = toBinary(num);
        cout << s << " ";
        int reflect = 0;
        for(int i = 0; i < s.size(); i++) {
            reflect = reflect * 2 + (s[i] - '0');
        }
        return reflect;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> temp;
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back({reflection(nums[i]), nums[i]});
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};