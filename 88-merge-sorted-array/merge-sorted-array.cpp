class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m;
        for(int i = 0; i < n; i++){
            nums1[idx] = nums2[i];
            idx++;
        }

        sort(nums1.begin(), nums1.end());
    }
};