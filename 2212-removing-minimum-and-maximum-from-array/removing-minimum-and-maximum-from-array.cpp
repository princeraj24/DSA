class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }

            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }

        // Make minIdx smaller than maxIdx
        if(minIdx > maxIdx){
            swap(minIdx, maxIdx);
        }

        // Remove both from left side
        int left = maxIdx + 1;

        // Remove both from right side
        int right = n - minIdx;

        // Remove min from left side and max from right side
        int both = (minIdx + 1) + (n - maxIdx);

        return min({left, right, both});
    }
};