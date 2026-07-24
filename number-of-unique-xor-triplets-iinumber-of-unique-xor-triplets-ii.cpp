class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<bool> twoXOR(2048, false); // max possible value of XOR(a, b) is 11 bit set bit(11111...) which equals to 2047
        vector<bool> threeXOR(2048, false); // max possible value of XOR(a, b, c) is 11 bit set bit(11111...) which equals to 2047

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                twoXOR[nums[i] ^ nums[j]] = true;
            }
        }

        for(int x = 0; x < 2048; x++){
            if(!twoXOR[x]){
                continue;
            }

            for(int num : nums){
                threeXOR[x ^ num] = true;
            }
        }

        int ans = 0;
        for(int i = 0; i < 2048; i++){
            if(threeXOR[i]){
                ans++;
            }
        }

        return ans;
    }
};
