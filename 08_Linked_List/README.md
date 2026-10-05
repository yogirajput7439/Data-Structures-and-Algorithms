# Intuition

A linked list can be reversed by changing the direction of each node's `next` pointer.

While traversing the list, we need three pointers:

* `prev` → points to the previous node.
* `current` → points to the node currently being processed.
* `next` → temporarily stores the next node so we don't lose the remaining list.

For every node, we reverse its connection:

`current->next = prev`

Then move both pointers forward until the entire list is reversed.

# Approach

1. Initialize `prev` as `nullptr` because the new tail will point to `nullptr`.
2. Set `current` to `head`.
3. While `current` is not `nullptr`:

   * Store the next node in `next`.
   * Reverse the current node's pointer by making `current->next` point to `prev`.
   * Move `prev` to `current`.
   * Move `current` to the saved `next` node.
4. When the loop ends, `prev` points to the new head of the reversed list.
5. Return `prev`.

For example:

`1 → 2 → 3 → nullptr`

becomes:

`3 → 2 → 1 → nullptr`

# Complexity

* Time complexity: **O(n)**

  Every node is visited exactly once.

* Space complexity: **O(1)**

  Only three pointers are used, so no extra data structure is required.

# Code

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while(current != nullptr) {

            ListNode* next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        return prev;
    }
};
```
