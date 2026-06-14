/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int pairSum(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *curr = slow;
    while (curr) {
        struct ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    int ans = 0;
    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second) {
        int sum = first->val + second->val;
        if (sum > ans) ans = sum;
        first = first->next;
        second = second->next;
    }

    return ans;
}
