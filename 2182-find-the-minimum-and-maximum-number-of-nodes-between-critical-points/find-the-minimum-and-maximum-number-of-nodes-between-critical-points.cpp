/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp;
        ListNode* curr = head;

        while(curr != NULL){
            temp.push_back(curr -> val);
            curr = curr -> next;
        }

        vector<int> criticPoint;
        for(int i = 1; i < temp.size()-1; i++){
            if(temp[i] > temp[i+1] && temp[i] > temp[i-1]){
                criticPoint.push_back(i);
            }
            
            else if(temp[i] < temp[i+1] && temp[i] < temp[i-1]){
                criticPoint.push_back(i);
            }

        }
        int n = criticPoint.size();
        if(n < 2){
            return {-1, -1};
        }

        sort(criticPoint.begin(), criticPoint.end());

        int mini = INT_MAX;
        int maxi = criticPoint[n-1] - criticPoint[0];
        
        for(int i = 1; i < criticPoint.size(); i++){
            if(criticPoint[i] - criticPoint[i-1] < mini){
                mini = criticPoint[i] - criticPoint[i-1];
            }
        }

        return {mini, maxi};
    }
};