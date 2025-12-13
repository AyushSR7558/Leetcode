class Solution {
    unordered_set<string> business = {"electronics", "grocery", "pharmacy", "restaurant"};
private:
    bool isValid(string code, string businessline, bool isActive) {
        if(!isActive) return false;
        if(code == "") return false;

        if(!business.count(businessline)) return false;

        for(int i = 0; i < code.size(); i++) {
            char ch = code[i];

            if(!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch == '_') )) return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int  n = code.size();
        vector<pair<string, string>> validCoupons;

        for(int i = 0; i < n; i++) {
            if(isValid(code[i],businessLine[i], isActive[i])) {
                validCoupons.push_back({code[i], businessLine[i]});
            } 
        }
        
        unordered_map<string, int> jobHierchy = {
            {"electronics", 1}, {"grocery", 2}, {"pharmacy", 3},{"restaurant", 4}
        };

        sort(validCoupons.begin(), validCoupons.end(), [&jobHierchy](pair<string, string>& a, pair<string, string>& b){
            if(a.second == b.second) {
                return a < b;
            }else {
                int rankOfA = jobHierchy[a.second];
                int rankOfB = jobHierchy[b.second];

                return (rankOfA < rankOfB? true: false);
            }
        });
    
        vector<string> ans;

        for(int i = 0; i < validCoupons.size(); i++) {
            ans.push_back(validCoupons[i].first);
        }

        return ans;
    }
};