// Remove Duplicates from Sorted List II
// Difficulty: Medium   Solved: 2026-10-07
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur) {
            bool duplicate = false;

            while (cur->next && cur->val == cur->next->val) {
                duplicate = true;
                cur = cur->next;
            }

            if (duplicate)
                prev->next = cur->next;
            else
                prev = prev->next;

            cur = cur->next;
        }

        return dummy.next;
    }
};
