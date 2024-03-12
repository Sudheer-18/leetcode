class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int pre = 0;
        ListNode* h = new ListNode(0);
        h->next = head;
        unordered_map<int, ListNode*> vis;
        for(auto i = h; i; i = i->next){
            vis[pre += i->val] = i;
        }
        pre = 0;
        for(auto i = h; i; i = i->next){
            i->next = vis[pre += i->val]->next;
        }
        return h->next;
    }
};