// link :https://leetcode.com/problems/intersection-of-two-linked-lists/

// sol 1 : hasing
    // 1. iterate linked list A and hash the addresses
    // 2. iterate linked list B and check if address is already exists or not
    //     1. if yes return the address
    //     2. else return null

// sol 2 :


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA==NULL || headB==NULL) return NULL;

        ListNode *d1 = headA;
        ListNode *d2 = headB;

        while(d1 != d2){
            d1 = d1==NULL ? headB : d1->next;
            d2 = d2==NULL ? headA : d2->next;
        }

        return d1;
    }
};
