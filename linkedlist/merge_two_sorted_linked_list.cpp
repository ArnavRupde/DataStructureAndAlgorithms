// link : https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp = new ListNode(-1);
        ListNode *ans = temp;

        ListNode *i = list1;
        ListNode *j = list2;

        while(i!=NULL && j!=NULL){
            if(i->val >= j->val){
                temp->next = j;
                temp = j;
                j = j->next;

            }
            else{
                temp->next = i;
                temp = i;
                i = i->next;

            }

        }
        if(i != NULL) temp->next = i;
 //         while(i != NULL){
 //                 temp->next = i;
 //                 temp = i;
 //                 i = i->next;

 //         }
         if(j != NULL) temp->next = j;
 //         while(j != NULL) {
 //                 temp->next = j;
 //                 temp = j;
 //                 j = j->next;

 //         }

    ans = ans->next;
    return ans;
    }
};
