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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        vector<int> arr;
        ListNode* curr = head;
        while (curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int l = arr.size() - 1;
        vector<int> v1;
        int i = 0, k = 0;
        while (i < arr.size()) {
            if (i % 2 == 0) {
                v1.push_back(arr[k]);
                k += 1;
            } else {
                v1.push_back(arr[l]);
                l -= 1;
            }
            i += 1;
        }

        curr = head;
        for (int i = 0; i < v1.size(); i++) {
            curr->val = v1[i];
            curr = curr->next;
        }
    }
};
