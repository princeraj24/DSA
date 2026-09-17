class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> freq1;
        for(int i = 0; i < n; i++){
            freq1[nums1[i]]++;
        }

        unordered_map<int, int> freq2;
        for(int i = 0; i < m; i++){
            freq2[nums2[i]]++;
        }

        vector<int> ans;
        for(int i = 0; i < m; i++){
            int val = nums2[i];

            if(freq1.find(val) != freq1.end() && freq2.find(val) != freq2.end()){
                int size = min(freq1[val], freq2[val]);
                for(int j = 0; j < size; j++){
                    ans.push_back(val);
                }

                freq1[val] = 0;
                freq2[val] = 0;
            }
        }

        return ans;
    }
};