class Solution {
private:
    bool canBePart(unordered_set<char> tempString, string currString) {
        int n = currString.size();
        for(int i = 0; i < n; i++) {
            if(tempString.find(currString[i]) != tempString.end()) return false;
            tempString.insert(currString[i]);
        }
        return true;
    }
    int solve(vector<string>& arr, unordered_set<char> tempString, int indx) {
        if(indx >= arr.size()) {
            return tempString.size();
        }
        //Not take
        int maxi = 0;
        maxi = max(solve(arr, tempString, indx + 1), maxi);
        bool isTrue = canBePart(tempString,arr[indx]);
        if(isTrue) {
            for(int i = 0; i < arr[indx].size(); i++) {
                tempString.insert(arr[indx][i]);
            }
            maxi = max(solve(arr,tempString, indx + 1), maxi);
        }
        return maxi;
    }
public:
    int maxLength(vector<string>& arr) {
        unordered_set<char> temp;
        return solve(arr, temp, 0);
    }
};