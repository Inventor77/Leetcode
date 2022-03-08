class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }
        while (head) {
            if (head->val == 1000000) {
                return true;
            }
            head->val = 1000000;
            head = head->next;
        }
        return false;
    }
};