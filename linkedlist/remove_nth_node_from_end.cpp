// link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// sol 1 :
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode *tempHead = head;

        while(tempHead != NULL){
            len++;
            tempHead = tempHead->next;
        }

        int targetNode = len-n-1;

        if(len==n){
            return head->next;
        }


        tempHead = head;
        ListNode *preOfTarget;

        while(targetNode--){
            tempHead = tempHead->next;
            preOfTarget = tempHead;
        }

        preOfTarget->next = tempHead->next->next;

    return head;
    }
};


// sol 2 : slow and fast pointer concept
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;

        while(n--) fast = fast->next;


        while(fast!=NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

    return start->next;
    }
};
