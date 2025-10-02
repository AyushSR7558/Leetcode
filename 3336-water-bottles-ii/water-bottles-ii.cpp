class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles, drk = numBottles;
        while(empty >= numExchange) {
            drk++;
            empty = empty - numExchange + 1;
            numExchange++;
        }
        return drk;
    }
};