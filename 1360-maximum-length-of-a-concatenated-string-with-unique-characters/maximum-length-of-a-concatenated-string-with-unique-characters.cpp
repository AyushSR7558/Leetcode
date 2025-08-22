class Solution {
private:
    bool canBePart(const unordered_set<char>& tempString, const string& currString) {
        unordered_set<char> seen;
        for(char c : currString) {
            if(tempString.count(c) || seen.count(c)) return false;
            seen.insert(c);
        }
        return true;
    }

    int solve(vector<string>& arr, unordered_set<char> tempString, int indx) {
        if(indx >= arr.size()) {
            return tempString.size(); // ✅ base case: return current length
        }

        // Option 1: Not take arr[indx]
        int maxi = solve(arr, tempString, indx + 1);

        // Option 2: Take arr[indx], only if possible
        if(canBePart(tempString, arr[indx])) {
            for(char c : arr[indx]) tempString.insert(c);
            maxi = max(maxi, solve(arr, tempString, indx + 1));
        }

        return maxi;
    }

public:
    int maxLength(vector<string>& arr) {
        unordered_set<char> temp;
        return solve(arr, temp, 0);
    }
};
