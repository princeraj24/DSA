class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> prefixSum(n+1, 0);
        prefixSum[0] = 0;
        for(int i = 0; i < n; i++){
            prefixSum[i+1] = prefixSum[i] + (s[i] - '0');
        }

        string ans;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= n; j++){
                string curr = s.substr(i, j - i);

                if(prefixSum[j] - prefixSum[i] == k) {

                    if(ans.empty() ||
                       curr.size() < ans.size() ||
                       (curr.size() == ans.size() && curr < ans)) {

                        ans = curr;
                    }
                }
            }
        }

        return ans;
    }
};