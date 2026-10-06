# LeetCode 67 — Add Binary

## Intuition

We need to add two binary numbers represented as strings.

Just like normal decimal addition, we start from the **rightmost digit** and maintain a `carry`.

For every position:

* Add the current digit from `a`.
* Add the current digit from `b`.
* Add the previous `carry`.
* The current binary digit is `sum % 2`.
* The new carry is `sum / 2`.

Since we process the strings from right to left, the answer is initially built in reverse order. Therefore, we reverse it at the end.

## Approach

1. Initialize an empty string `ans`.
2. Set `carry = 0`.
3. Start from the last characters of both strings using:

   * `i = a.length() - 1`
   * `j = b.length() - 1`
4. Continue while either string still has digits or `carry` is present.
5. Add the current digit of `a` if `i >= 0`.
6. Add the current digit of `b` if `j >= 0`.
7. Store `carry % 2` as the current binary digit.
8. Update `carry` using `carry /= 2`.
9. Reverse `ans` because digits were added from right to left.
10. Return the result.

## Example

Input:

```text
a = "1010"
b = "1011"
```

Binary addition:

```text
   1010
 + 1011
 ------
  10101
```

Output:

```text
"10101"
```

## How Carry Works

For binary addition:

```text
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10
```

When:

```text
1 + 1 = 2
```

In binary, `2` is `10`.

Therefore:

```text
2 % 2 = 0   → current digit
2 / 2 = 1   → carry
```

This is exactly what the code does:

```cpp
ans += carry % 2 + '0';
carry /= 2;
```

## Complexity

### Time Complexity

```text
O(max(n, m))
```

where `n` and `m` are the lengths of the two input strings.

We process each digit at most once.

### Space Complexity

```text
O(max(n, m))
```

The result string requires space proportional to the length of the input.

## C++ Solution

```cpp
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';

      if (j >= 0)
        carry += b[j--] - '0';

      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));

    return ans;
  }
};
```

## Key Idea

The core idea is:

```text
Add from right → calculate digit → store carry → move left
```

Because binary numbers work exactly like decimal addition, the only difference is that the base is `2` instead of `10`.

## Pattern

**String + Binary Arithmetic + Two Pointers + Carry**
