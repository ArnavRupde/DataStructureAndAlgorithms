// https://leetcode.com/problems/palindrome-linked-list/


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
    bool isPalindrome(ListNode* head) {
        // find middle of linked list
        ListNode *mid = middleOfLinkedList(head);

        // reverse right half part
        mid->next = reverse_right_half(mid->next);

        ListNode *left_half_start = head;
        ListNode *right_half_start = mid->next;

        // check for palindrome
        while(right_half_start!=NULL){
            if(left_half_start->val != right_half_start->val){
                return false;
            }

            left_half_start = left_half_start->next;
            right_half_start = right_half_start->next;
        }

        return true;
    }

    ListNode* middleOfLinkedList(ListNode *head){
        ListNode *dummy_node = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse_right_half(ListNode *head){
        ListNode *temp = NULL;

        while(head!=NULL){
            ListNode *next_node = head->next;
            head->next = temp;
            temp = head;
            head = next_node;
        }

        return temp;
    }

};
