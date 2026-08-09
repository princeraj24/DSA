class Solution {
public:
    double power(double x, long long N){
        if(N == 0){
            return 1;
        }

        double half = power(x, N/2);
        double result = half * half;
        if(N % 2 == 1){
            result *= x;
        }

        return result;
    }
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            return 1 / power(x, -N);
        }

        return power(x, N);
    }
};