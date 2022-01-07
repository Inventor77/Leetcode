class Solution {
    ListNode* copy;
public:
    Solution(ListNode* head) {
        copy = head;
    }
    int getRandom()
    {
        ListNode* temp = copy;
        int pos = 1, res;
        while (temp)
        {
            if (rand() % pos == 0)
                res = temp->val;
            temp = temp->next;
            pos++;
        }
        return res;
    }
};