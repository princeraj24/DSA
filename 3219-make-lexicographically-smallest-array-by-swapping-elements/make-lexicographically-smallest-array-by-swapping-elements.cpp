class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        // sort the vec
        sort(vec.begin(), vec.end());

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]); // O(1) {1, 2, 3, 4, 5}

        for(int i = 1; i < n; i++){
            if(abs(vec[i] - vec[i-1]) > limit){
                groupNum++;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        // Build the answer - Merge the groups
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int group = numToGroup[num];

            // smallest available number in this group
            result[i] = *(groupToList[group].begin()); // use ho gaya to delete kr do
            groupToList[group].pop_front();
        }
        return result;
    }
};