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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* new_head = head->next; 
        while (current && current->next) {
            ListNode* next_pair = current->next->next;
            ListNode* second = current->next;
            second->next = current;
            current->next = next_pair;
            if (prev) {
                prev->next = second;
            }
            prev = current;
            current = next_pair;
        }

        return new_head;
    }
};
