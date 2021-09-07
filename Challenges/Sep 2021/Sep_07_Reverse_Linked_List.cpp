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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};



// --------------- 0ms Submission ---------------------
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next) return head;
//         ListNode* nh = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return nh;
//     }
// };
// -------------- 8100KB Submission -------------------
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* current = nullptr;
//         ListNode* next;
//         while (head != nullptr) {
//             next = head->next;
//             head->next = current;
//             current = head;
//             head = next;
//         }
//         return current;
//     }
// };
// ----------------------------------------------------