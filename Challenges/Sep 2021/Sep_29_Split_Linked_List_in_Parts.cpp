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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;temp = temp->next;
        }
        if (n <= k) {
            temp = head;
            while (temp) {
                ListNode* nxt = temp->next;
                temp->next = NULL;
                ans.push_back(temp);
                temp = nxt;
            }
            n = k - n;
            while (n--) {
                ans.push_back(NULL);
            }
            return ans;
        }

        temp = head;
        int nolparts = k;
        int ext = n % k;
        while (nolparts--) {
            ans.push_back(temp);
            int f_sz = n / k;
            if (ext > 0) {
                f_sz += 1;
                ext--;
            }

            while (f_sz > 1) {
                temp = temp->next;
                f_sz--;
            }
            ListNode* nxt = temp->next;
            temp->next = NULL;
            temp = nxt;
        }
        return ans;
    }
};