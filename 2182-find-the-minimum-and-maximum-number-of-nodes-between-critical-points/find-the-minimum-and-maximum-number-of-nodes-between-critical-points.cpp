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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        
        vector<int> criticalPositions;
        int position = 1; // 1-based index
        
        while (next != nullptr) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPositions.push_back(position);
            }
            
            prev = curr;
            curr = next;
            next = next->next;
            position++;
        }
        
        if (criticalPositions.size() < 2) return {-1, -1};
        
        int minDistance = INT_MAX;
        for (int i = 1; i < criticalPositions.size(); i++) {
            minDistance = min(minDistance, criticalPositions[i] - criticalPositions[i-1]);
        }
        
        int maxDistance = criticalPositions.back() - criticalPositions.front();
        
        return {minDistance, maxDistance};
    }
};
