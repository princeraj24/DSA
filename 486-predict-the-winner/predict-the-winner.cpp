class Solution {
public:
    bool isValid(int i, int j, int score1, int score2, vector<int>& nums){
        if(i > j){
            return score1 >= score2;
        }

        if(i == j){
            return score1 + nums[i] >= score2;
        }

        // Player 1 takes left
        bool left = true;
        
        // Player 2 takes right
        left &= isValid(i + 1, j - 1, score1 + nums[i], score2 + nums[j], nums);
        // Player 2 takes left
        left &= isValid(i + 2, j, score1 + nums[i], score2 + nums[i+1], nums);
        


        // Player 1 takes right
        bool right = true;

        // Player 2 takes left
        right &= isValid(i + 1, j - 1, score1 + nums[j], score2 + nums[i], nums);
        // Player 2 takes right
        right &= isValid(i, j - 2, score1 + nums[j], score2 + nums[j - 1], nums);

        return left || right;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        return isValid(0, n-1, 0, 0, nums);
    }
};