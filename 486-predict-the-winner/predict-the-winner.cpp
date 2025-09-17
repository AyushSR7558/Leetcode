class Solution {
private:
    int minimax(int i, int j, int turn, vector<int>& nums) {
    if(i > j) return 0;

    if(turn % 2 == 0) { // Player 1's turn (maximize)
        return max(nums[i] + minimax(i+1, j, turn+1, nums),
                   nums[j] + minimax(i, j-1, turn+1, nums));
    } else { // Player 2's turn (minimize Player 1's final score)
        return min(-nums[i] + minimax(i+1, j, turn+1, nums),
                   -nums[j] + minimax(i, j-1, turn+1, nums));
    }
}
public:
    bool predictTheWinner(vector<int>& nums) {
        int val = minimax(0, nums.size() - 1, 0, nums);
        return val >= 0;
    }
};