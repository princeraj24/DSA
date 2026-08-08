class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = maximum number of characters of word2
        // that can be matched as a subsequence from word1[i...]
        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for(int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];

            if(j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;
        int k = 0;
        j = 0;
        bool used = false;

        for(int i = 0; i < n && k < m; i++) {

            // Current character matches
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                k++;
                j++;
            }

            // Use the one allowed mismatch
            else if(!used) {

                // After choosing i, can the remaining
                // characters of word2 be formed?
                if(suf[i + 1] >= m - j - 1) {
                    ans.push_back(i);
                    k++;
                    j++;
                    used = true;
                }
            }
        }

        if(k == m) {
            return ans;
        }

        return {};
    }
};