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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        ListNode* cpy = head;
        vector<int> arr;
        while (cpy != nullptr) {
            if (num_set.find(cpy->val) == num_set.end()) {
                arr.push_back(cpy->val);
            }
            cpy = cpy->next;
        }
        if (arr.empty()) return nullptr;
        ListNode* ans = new ListNode(arr[0]);
        ListNode* tail = ans; 
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new ListNode(arr[i]);
            tail = tail->next;
        }
        return ans;
    }
};