class Solution {
public:
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto list : lists) if (list != nullptr) q.push(list);

        ListNode* head = nullptr;
        ListNode* node = nullptr;
        while (!q.empty()) {
            if (head == nullptr) {
                node = new ListNode();
                head = node;
            }
            else {
                node->next = new ListNode();
                node = node->next;
            }
            ListNode* e = q.top();
            q.pop();
            if (e->next != nullptr) q.push(e->next);
            node->val = e->val;
        }
        return head;
    }
};