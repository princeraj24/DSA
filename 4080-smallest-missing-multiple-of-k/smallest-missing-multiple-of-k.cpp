class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int expected = k;

        for(int val : nums){
            if(expected == val){
                expected += k;
            }
        }

        return expected;
    }
};