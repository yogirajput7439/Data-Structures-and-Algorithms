# LeetCode 1541 — Minimum Insertions to Balance a Parentheses String

## Intuition

We are given a string containing only `(` and `)`.

The goal is to find the minimum number of insertions required to make the parentheses balanced.

In this problem, every opening parenthesis `(` must be matched with **two consecutive closing parentheses `))`**.

For example:

```text
"())"     → Balanced
"(()))"   → Balanced
"())())"  → Balanced
```

Instead of inserting parentheses and modifying the string, we can use a greedy approach with two variables:

* `ans`: Counts the insertions already performed.
* `need`: Tracks how many closing parentheses are still required to balance the opening parentheses.

We process each character from left to right and make the minimum necessary corrections immediately.

## Approach

1. Initialize `ans = 0` and `need = 0`.
2. Traverse every character in the string.

### Case 1: Current character is `(`

Each opening parenthesis requires two closing parentheses, so:

```cpp
need += 2;
```

However, the number of required closing parentheses must remain even when we are waiting to complete opening-parenthesis pairs.

If `need` becomes odd, we insert one `)` to complete the previous requirement:

```cpp
if (need % 2 != 0) {
    ans++;
    need--;
}
```

### Case 2: Current character is `)`

We use one required closing parenthesis:

```cpp
need--;
```

If `need` becomes negative, there was no available opening parenthesis to match this closing parenthesis.

We must insert an opening parenthesis and one additional closing parenthesis:

```cpp
if (need < 0) {
    ans++;
    need = 1;
}
```

The inserted `(` requires two closing parentheses, and the current `)` satisfies one of them. Therefore, one closing parenthesis remains required.

3. After processing the entire string, insert all remaining required closing parentheses.

```cpp
return ans + need;
```

## Example

**Input:**

```text
s = "(()))"
```

Initially:

```text
ans = 0
need = 0
```

| Character | Operation   | `ans` | `need` |
| --------- | ----------- | ----: | -----: |
| `(`       | `need += 2` |     0 |      2 |
| `(`       | `need += 2` |     0 |      4 |
| `)`       | `need--`    |     0 |      3 |
| `)`       | `need--`    |     0 |      2 |
| `)`       | `need--`    |     0 |      1 |

One closing parenthesis is still required.

Therefore:

```text
ans + need = 0 + 1 = 1
```

**Output:**

```text
1
```

## C++ Solution

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char ch : s) {
            if (ch == '(') {
                need += 2;

                if (need % 2 != 0) {
                    ans++;
                    need--;
                }
            }
            else {
                need--;

                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};
```

## Complexity Analysis

### Time Complexity

**O(n)**

We traverse the string exactly once, where `n` is the length of the string.

### Space Complexity

**O(1)**

We use only two integer variables, `ans` and `need`, regardless of the input size.

## Key Pattern

**Greedy Algorithm + Counter + Parentheses Balancing**

The important idea is to track how many closing parentheses are needed instead of explicitly building the balanced string.

* `ans` tracks insertions already made.
* `need` tracks closing parentheses still required.

## Important Observation

The key difference from ordinary parentheses problems is that each `(` requires **two** closing parentheses.

That is why we use:

```cpp
need += 2;
```

And why we maintain the parity of `need`:

```cpp
if (need % 2 != 0)
```

Keeping `need` even when processing opening parentheses ensures that the remaining closing parentheses can be grouped correctly into pairs.

This greedy strategy finds the minimum number of insertions in linear time.

