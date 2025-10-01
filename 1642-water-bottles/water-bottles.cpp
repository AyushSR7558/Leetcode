class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remBottle = numBottles, drkBottle = numBottles;
        while(remBottle >= numExchange) {
            drkBottle += remBottle / numExchange;
            remBottle = remBottle / numExchange + remBottle % numExchange;
        }
        return drkBottle;
    }
};