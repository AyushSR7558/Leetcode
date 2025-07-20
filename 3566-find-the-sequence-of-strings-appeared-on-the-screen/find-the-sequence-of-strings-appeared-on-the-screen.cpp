class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string temp = "";
        int indx = 0;
        while(indx < target.size()){
            temp += "a";
            ans.push_back(temp);
            while(temp.back() != target[indx]){
                char simp = temp.back();
                temp[temp.size() - 1] = (simp + 1);
                ans.push_back(temp);
            }
            indx++;
        }
        return ans;
    }
};