# LeetCode 344 — Reverse String

## Intuition

We need to reverse the given character array **in-place**.

Instead of creating another array, we can use the **Two Pointer** approach:

* `st` points to the first character.
* `end` points to the last character.
* Swap both characters.
* Move `st` forward.
* Move `end` backward.
* Continue until both pointers meet.

This reverses the array using **constant extra space**.

## Approach

1. Initialize:

   ```cpp
   int st = 0;
   int end = s.size() - 1;
   ```

2. While `st < end`:

   * Swap `s[st]` and `s[end]`.
   * Increment `st`.
   * Decrement `end`.

3. Stop when `st >= end`.

Because every pair of characters is swapped exactly once, the array becomes reversed.

## Example

Input:

```text
s = ['h','e','l','l','o']
```

Initially:

```text
h e l l o
↑       ↑
st     end
```

Swap:

```text
o e l l h
```

Move pointers:

```text
o e l l h
  ↑   ↑
 st  end
```

Swap:

```text
o l l e h
```

Continue until the pointers meet.

Final result:

```text
['o','l','l','e','h']
```

## C++ Solution

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int end = s.size() - 1;

        while (st < end) {
            swap(s[st], s[end]);
            st++;
            end--;
        }
    }
};
```

## Complexity

### Time Complexity

```text
O(n)
```

Each character is involved in at most one swap.

### Space Complexity

```text
O(1)
```

We reverse the array **in-place**, so no extra array is created.

## Key Pattern

**Two Pointers + In-Place Array Manipulation**

The general pattern is:

```text
left →              ← right
[ a  b  c  d  e  f ]

swap(left, right)

[ f  b  c  d  e  a ]
```

Then move both pointers toward the center.

## Important Point

This problem is a classic example of the **Two Pointer Pattern**.

Whenever you need to reverse an array/string **in-place**, think:

```text
left = 0
right = n - 1

while (left < right):
    swap(left, right)
    left++
    right--
```
