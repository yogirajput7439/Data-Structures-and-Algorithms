## Intuition
We need to sort a linked list in ascending order. Merge Sort is optimal for this problem because it divides the linked list into smaller halves, sorts them recursively, and merges the sorted halves.

## Approach
1. **Base Case:** If the list is empty or contains only one node, return it.
2. **Find the Middle:** Use the slow and fast pointer technique to find the middle of the linked list.
3. **Split the List:** Disconnect the first half from the second half.
4. **Recursive Sorting:** Recursively sort both halves using `sortList()`.
5. **Merge:** Merge both sorted halves using `mergelist()` by comparing node values.
6. Return the merged sorted list.

## Complexity
- **Time Complexity:** O(n log n), where `n` is the number of nodes.
- **Space Complexity:** O(log n) auxiliary space due to recursion. The merge operation reuses existing nodes, although the dummy node allocation in this implementation adds constant-sized allocations per merge.

## Code
```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // If list contains a single or 0 node
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        // Find the middle element using slow and fast pointers
        while (fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;  // End of the first half

        ListNode* l1 = sortList(head);  // Sort left half
        ListNode* l2 = sortList(slow);  // Sort right half

        return mergelist(l1, l2);       // Merge both halves
    }

    ListNode* mergelist(ListNode *l1, ListNode *l2) {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        // Attach the remaining nodes
        if (l1 != NULL) {
            curr->next = l1;
        }

        if (l2 != NULL) {
            curr->next = l2;
        }

        return ptr->next;
    }
};
```
