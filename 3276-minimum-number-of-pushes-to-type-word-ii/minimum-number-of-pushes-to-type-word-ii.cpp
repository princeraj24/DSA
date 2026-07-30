class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        // store freq in a vector of size 26
        vector<int> freq(26, 0);
        for(char ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());  // sort based on freq. in descending order
        int result = 0;
        for(int i = 0; i < 26; i++){
            int cnt = freq[i];
            int press = (i/8 + 1);

            result += cnt * press;
        }
        
        return result;
    }
};