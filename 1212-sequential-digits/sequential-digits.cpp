class Solution {
private:
    void helper(vector<int>& arr, int low, int high, int s) {
        if(s > high) {
            return ;
        }

        if(s >= low) {
            arr.push_back(s);
        }
        int lastDigit = s % 10;
        if(lastDigit + 1 <= 9) {
            helper(arr, low, high, s * 10 + lastDigit + 1);
        }
    }
    int fDigit(int num) {
        int prev = num % 10;
        while(num) {
            prev = num % 10;
            num /= 10;
        }
        return prev;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr;

        for(int i = 1; i <= 9; i++) {
            helper(arr, low, high, i);
        }

        sort(arr.begin(), arr.end());
        
        return arr;

    }
    };
