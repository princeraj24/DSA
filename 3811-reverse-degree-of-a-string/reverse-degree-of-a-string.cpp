class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            int currAsc = s[i] - 'a';
            
            sum += (26 - currAsc) * (i + 1);
        }

        return sum;
    }
};