/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    
    struct ListNode dummy = {0, head};
    struct ListNode* prev = &dummy;
    
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }
    
    struct ListNode* current = prev->next;
    struct ListNode* next = NULL;
    struct ListNode* reverseTail = current;

    for (int i = 0; i < right - left + 1; ++i) {
        next = current->next;
        current->next = prev->next;
        prev->next = current;
        current = next;
    }
    
    reverseTail->next = current;

    return dummy.next;
    
}
