class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }

        long long target = total - x;
        if(target == 0){
            return n;
        }

        if(target < 0){
            return -1;
        }

        int i = 0;
        int j = 0;
        int maxLen = -1;
        long long sum = 0;

        // Apply sliding window to find max size of subarray exist whose sum is equal to target so that the rest size sum equals to x is minimum.
        while(j < n){
            sum += nums[j];

            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }

            if(target == sum){
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }

        return (maxLen == -1) ? -1 : n - maxLen;
    }
};