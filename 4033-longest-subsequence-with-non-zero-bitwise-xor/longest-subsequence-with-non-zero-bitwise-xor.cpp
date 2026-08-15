class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor_val = 0;
        bool allZeros = true;
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                allZeros = false;
            }
            xor_val = xor_val ^ nums[i];
        }

        if(allZeros){
            return 0;
        }

        if(xor_val != 0){
            return n;
        }

        return n-1;
    }
};