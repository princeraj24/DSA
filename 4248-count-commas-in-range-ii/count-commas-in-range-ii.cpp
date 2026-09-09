class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }

        long long lower = 1000;
        int comma = 1;
        long long ans = 0;
        while(lower <= n){
            long long upper = lower * 1000 - 1;
            if(upper > n){
                upper = n;
            }

            long long countNos = (upper - lower + 1);
            ans += countNos * comma;

            comma++;
            lower = lower * 1000;
        }

        return ans;
    }
};