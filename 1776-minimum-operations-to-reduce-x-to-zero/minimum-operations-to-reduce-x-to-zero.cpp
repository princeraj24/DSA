class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;
        for(int num : nums){
            total += num;
        }

        long long target = total - x;

        if(target < 0){
            return -1;
        }

        // target == 0 means remove everything
        if(target == 0){
            return n;
        }

        int i = 0;
        long long sum = 0;
        int maxLen = -1;

        for(int j = 0; j < n; j++){
            sum += nums[j];

            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }

            if(sum == target){
                maxLen = max(maxLen, j - i + 1);
            }
        }

        if(maxLen == -1){
            return -1;
        }

        return n - maxLen;
    }
};