// link : https://leetcode.com/problems/add-two-numbers/
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
      ListNode *start = new ListNode();
      ListNode *head = start;
      int carry = 0;
      int curr_sum;

      while(l1 != NULL && l2 != NULL){
        curr_sum = l1->val + l2->val + carry;
        carry = curr_sum/10;
        ListNode *temp = new ListNode(curr_sum%10);

        start->next = temp;
        start=temp;

        l1=l1->next;
        l2=l2->next;
      }

      while(l1!=NULL){
        curr_sum = l1->val + carry;
        carry = curr_sum/10;
        l1->val = curr_sum%10;

        start->next = l1;
        start=l1;

        l1=l1->next;
      }

      while(l2!=NULL){
        curr_sum = l2->val + carry;
        carry = curr_sum/10;
        l2->val = curr_sum%10;

        start->next = l2;
        start=l2;

        l2=l2->next;
      }

      if(carry==1){
        ListNode *temp = new ListNode(1);
        start->next=temp;
      }

    return head->next;
    }
};
