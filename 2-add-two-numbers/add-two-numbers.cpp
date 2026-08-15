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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* ans = new ListNode();
        ListNode* finalHead = ans;
        while(head1 != NULL && head2 != NULL){
            
            int sum = carry + head1->val + head2->val;
            
            carry = sum / 10;
            
            ans -> val = sum % 10;


            head1 = head1 -> next;
            head2 = head2 -> next;

            if(head1 != NULL || head2 != NULL){
                ans -> next = new ListNode();
                ans = ans -> next;
            }
        }

        while(head1 != NULL){
            int sum = head1 -> val + carry;

            carry = sum / 10;
            
            ans -> val = sum % 10;

            head1 = head1 -> next;

            if(head1 != NULL){
                ans -> next = new ListNode();
                ans = ans -> next;
            }
        
        }

        while(head2 != NULL){
            int sum = head2 -> val + carry;
            
            carry = sum / 10;
            
            ans -> val = sum % 10;

            head2 = head2 -> next;
            
            if(head2 != NULL){
                ans -> next = new ListNode();
                ans = ans -> next;
            }

        }

        if(carry == 1){
            ans -> next = new ListNode(carry);
        }

        return finalHead;
    }
};