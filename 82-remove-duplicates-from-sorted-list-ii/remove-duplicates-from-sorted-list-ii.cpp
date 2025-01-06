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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        while(head != nullptr) {
            int val = head->val;
            if(mp.find(val) == mp.end()) mp[val]++;
            else {
                mp[val] = -1;
            }
            head = head->next;
        }
        ListNode* tmp = new ListNode(-1);
        ListNode* ans = tmp;
        for(auto i : mp) {
            if(i.second != -1) {
                tmp->next = new ListNode(i.first);
                tmp = tmp->next;
            }
        }

        return ans->next;;
    }
};