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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k, nullptr); 
        ListNode* current = head;
        int length = 0;
        while (current) {
            length++;
            current = current->next;
        }
        int partSize = length / k;
        int extraParts = length % k;
        current = head;
        for (int i = 0; i < k; ++i) {
            ListNode* partHead = current;
            int currentPartSize = partSize + (i < extraParts ? 1 : 0);
            for (int j = 1; j < currentPartSize; ++j) {
                if (current) current = current->next;
            }
            if (current) {
                ListNode* nextPart = current->next;
                current->next = nullptr;
                current = nextPart;
            }
            parts[i] = partHead;
        }

        return parts;
    }
};