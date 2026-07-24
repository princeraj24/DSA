class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2){
            return n;
        }

        int i = 2;
        while((1 << i) <= n){
            i++;
        }

        return (1 << i);
    }
};