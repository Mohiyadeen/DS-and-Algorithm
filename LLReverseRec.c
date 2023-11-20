// Function to reverse a linked list using recursion
struct ListNode* reverseListRecursive(struct ListNode* head) {
    // Base case: an empty list or a list with only one node is already reversed
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursive case: reverse the rest of the list
    struct ListNode* restReversed = reverseListRecursive(head->next);

    // Adjust the pointers to reverse the current node
    head->next->next = head;
    head->next = NULL;

    // Return the new head of the reversed list
    return restReversed;
}
