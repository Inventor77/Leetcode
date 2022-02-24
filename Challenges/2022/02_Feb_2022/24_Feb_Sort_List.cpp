class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
        {
            return  NULL;
        }
        vector<pair<int, ListNode*>> vec;
        while (head)
        {
            vec.push_back({ head->val, head });
            head = head->next;
        }

        sort(vec.begin(), vec.end());
        ListNode* temp = vec[0].second;
        for (int i = 1; i < vec.size(); i++)
        {
            temp->next = vec[i].second;
            temp = vec[i].second;
        }
        vec[vec.size() - 1].second->next = NULL;
        return vec[0].second;
    }
};