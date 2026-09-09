class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }

        long long start = 1000;
        long long ans = 0;
        while(start <= n){
            ans += (n - start + 1);

            start = start * 1000;
        }

        return ans;
    }
};