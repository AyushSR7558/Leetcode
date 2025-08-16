class Solution {
private:
    int changeS(string& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] == '6') {
                arr[i] = '9';
                break;
            }
        }
        return stoi(arr);
    }
public:
    int maximum69Number (int num) {
        string S = to_string(num);
        return changeS(S);
    }
};