class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        unordered_map<int, int> mp;
        int assign_key = 2;
        int output = 0;

        for(char ch : word){
            if(assign_key > 9){
                assign_key = 2;
            }

            mp[assign_key]++;
            output += mp[assign_key];
            
            assign_key++;
        }

        return output;
    }
};