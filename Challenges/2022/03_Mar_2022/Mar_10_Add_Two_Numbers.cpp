class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2)
    {
        ListNode* temp = new ListNode();
        ListNode* ans = temp;
        long long sum = 0, c = 0;
        while (head1 || head2 || c)
        {
            sum = 0;
            if (head1)
            {
                sum += head1->val;
                head1 = head1->next;
            }
            if (head2)
            {
                sum += head2->val;
                head2 = head2->next;
            }
            sum += c;
            ListNode* var = new ListNode(sum % 10);
            c = sum / 10;
            temp->next = var;
            temp = temp->next;
        }
        return ans->next;
    }
};