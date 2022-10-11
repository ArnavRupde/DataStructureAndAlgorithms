// link : https://leetcode.com/contest/weekly-contest-281/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *start = new ListNode(0);
        ListNode *temp = start;
        head = head->next;
        int curr_sum = 0;
        while(head != NULL){
            if(head->val == 0){
                ListNode *t = new ListNode(curr_sum);
                temp->next = t;
                temp = t;

                curr_sum = 0 ;
            }
            else curr_sum+=head->val;

            head = head->next;
        }

        return start->next;
    }
};
