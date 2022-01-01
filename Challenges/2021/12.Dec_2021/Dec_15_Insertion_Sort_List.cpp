class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> a;
        ListNode* temp = head;
        while (temp != NULL)
        {
            a.push_back(temp->val);
            temp = temp->next;
        }
        sort(a.begin(), a.end());
        ListNode* temp2 = head;
        int i = 0;
        while (temp2 != NULL)
        {
            temp2->val = a[i];
            temp2 = temp2->next;
            i++;
        }
        return head;
    }
};