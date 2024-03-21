class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* x = NULL;
        while (temp != NULL) {
            ListNode* y = new ListNode(temp->val);
            y->next = x;
            x = y;
            temp = temp->next;
        }
        return x;
    }
};
