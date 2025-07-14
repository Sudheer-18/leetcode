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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        cnt--;
        ListNode* dummy = head;
        while(dummy != nullptr) {
            ans += (pow(2,cnt) * dummy->val);
            cnt--;
            dummy = dummy->next;
        }

        return ans;
    }
};