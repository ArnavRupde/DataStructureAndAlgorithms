// link : https://leetcode.com/problems/middle-of-the-linked-list/
// link 2 : https://www.youtube.com/watch?v=sGdwSH8RK-o&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma

// sol 1 : find length of linked list and return

// sol2 : use two popinter algo

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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next!=NULL){

            slow = slow->next;
            // cout<<fast->val<<endl;
            fast = fast->next->next;

        }

        return slow;
    }
};
