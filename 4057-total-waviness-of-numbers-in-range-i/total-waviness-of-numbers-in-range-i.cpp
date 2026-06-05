class Solution {
private:
    int calWavinessOfNumber(int num) {
        int cnt = 0;
        int prev = num % 10;
        num /= 10;
        int curr = num % 10;
        num /= 10;

        while(num) {
            int next = num % 10;
            num /= 10;

            if(next > curr && curr < prev) cnt++;
            if(next < curr && curr > prev) cnt++;

            prev = curr;
            curr = next;
        }

        return cnt;
    }
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0; // Count the waviness of all the number

        if(num2 <= 100) {
            return 0;
        }

        for(int i = max(num1, 100); i <= num2; i++) {
            cnt += calWavinessOfNumber(i);
        }

        return cnt;
    }
};