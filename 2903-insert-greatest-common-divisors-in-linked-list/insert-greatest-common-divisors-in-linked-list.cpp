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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head; 
        ListNode* cpy = head;
        while (cpy != nullptr && cpy->next != nullptr) {
            int val = gcd(cpy->val, cpy->next->val);
            ListNode* new_node = new ListNode(val);
            new_node->next = cpy->next; 
            cpy->next = new_node;     
            cpy = new_node->next;        
        }
        
        return head;
    }
};
