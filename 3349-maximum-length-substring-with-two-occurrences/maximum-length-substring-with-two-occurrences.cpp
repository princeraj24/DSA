class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        int i = 0, j = 0;
        int maxi = INT_MIN;

        while(j < n){
            freq[s[j] - 'a']++;

            while(freq[s[j] - 'a'] > 2){
                freq[s[i] - 'a']--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }

        return maxi;
    }
};