# LeetCode 58 — Length of Last Word

## Intuition

We need to find the length of the **last word** in a string.

A word is a sequence of non-space characters.

The easiest way is to start from the **end of the string** because we only need the last word.

There may be spaces after the last word, so we first ignore those spaces.

Once we find a non-space character, we start counting.

When we encounter a space after counting has started, we know that the last word has ended.

## Approach

We use two variables:

```cpp
int length = 0;
bool counting = false;
```

* `length` stores the length of the last word.
* `counting` tells us whether we have already found the last word.

We traverse the string from right to left.

### Case 1: Current character is not a space

```cpp
if (s[i] != ' ')
```

We are inside the last word.

So:

```cpp
counting = true;
length++;
```

### Case 2: Current character is a space

If we have already started counting:

```cpp
else if (counting)
    break;
```

The last word is complete, so we stop.

## Example

Input:

```text
s = "Hello World"
```

Start from the end:

```text
Hello World
          ↑
```

We find:

```text
d → length = 1
l → length = 2
r → length = 3
o → length = 4
W → length = 5
```

Next character is a space.

So we stop.

Output:

```text
5
```

### Example with trailing spaces

```text
s = "Hello World   "
```

We first skip:

```text
"   "
```

Then start counting `World`.

Result:

```text
5
```

## C++ Solution

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool counting = false;

        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] != ' ') {
                counting = true;
                length++;
            }
            else if (counting) {
                break;
            }
        }

        return length;
    }
};
```

## Complexity

### Time Complexity

```text
O(n)
```

In the worst case, we may traverse the entire string.

### Space Complexity

```text
O(1)
```

We use only a few variables and don't create another string.

## Key Pattern

**String Traversal + Right-to-Left Scanning**

Whenever a problem asks for something related to the **last element/word/group** of a string, consider scanning from the right.

The general pattern is:

```text
Start from right
      ↓
Skip unnecessary characters
      ↓
Start counting/processing
      ↓
Stop when boundary is found
```

## Important Edge Cases

### Single word

```text
"Hello"
→ 5
```

### Multiple spaces between words

```text
"Hello   World"
→ 5
```

### Trailing spaces

```text
"Hello World   "
→ 5
```

### Single character

```text
"a"
→ 1
```

## Main Takeaway

Instead of splitting the entire string into words, we scan from the end and find the last word directly.

This gives:

```text
Time  → O(n)
Space → O(1)
```

and avoids creating extra arrays/strings.
