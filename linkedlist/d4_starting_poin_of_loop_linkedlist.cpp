// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// sol1 : hash the addresses and check every time during iteration , if exists return that address
// tc = O(N) , sc = O(N) => interviewer will not be happy => optimize this

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while(slow!=NULL && fast!=NULL && fast->next!=NULL ){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                // collision of slow and fast , i m sure that there is a cycle
                break;
            }
        }

        fast = head;
        while(slow!=fast && slow!=NULL && fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};
