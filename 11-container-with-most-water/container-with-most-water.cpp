class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = INT_MIN;

        int i = 0;
        int j = n-1;
        while(i < j){
            int wd = j - i;
            int ht = min(height[i], height[j]);

            maxArea = max(maxArea, wd * ht);

            if(height[i] > height[j]){
                j--;
            }

            else{
                i++;
            }
        }

        return maxArea;
    }
};