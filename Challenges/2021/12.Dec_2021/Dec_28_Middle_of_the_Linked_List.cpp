class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;

        while (fast->next != NULL) {
            slow = slow->next;
            if (fast->next->next != NULL)
                fast = fast->next->next;
            else
                return slow;
        }
        return slow;
    }
};