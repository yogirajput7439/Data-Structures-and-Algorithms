# LeetCode 1342 – Number of Steps to Reduce a Number to Zero

## Solution 1: Python – Iterative (Normal Approach)

**# Intuition**

We need to reduce the given number to zero using two operations. If the number is even, divide it by 2. If it is odd, subtract 1. We can use a while loop to perform these operations and count the total steps.

**# Approach**

1. Initialize `ans = 0`.
2. Run a while loop until `num` becomes zero.
3. If the number is even, divide it by 2.
4. Otherwise, subtract 1.
5. Increment `ans` after every operation.
6. Return the total steps.

**# Complexity**

- Time complexity: O(log n)
- Space complexity: O(1)

**# Code**
```python
class Solution:
    def numberOfSteps(self, num: int) -> int:
        ans = 0

        while num > 0:
            if num % 2 == 0:
                num //= 2
            else:
                num -= 1

            ans += 1

        return ans
```

---

## Solution 2: Python – Recursion

**# Intuition**

Instead of using a loop, we can solve the problem recursively. Each recursive call performs one operation and adds 1 to the total number of steps.

**# Approach**

1. If `num == 0`, return 0 (base case).
2. If the number is even, recursively call the function with `num // 2`.
3. If the number is odd, recursively call the function with `num - 1`.
4. Add 1 for every recursive operation.
5. Continue until the base case is reached.

**# Complexity**

- Time complexity: O(log n)
- Space complexity: O(log n), due to the recursion call stack.

**# Code**
```python
class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0

        if num % 2 == 0:
            return 1 + self.numberOfSteps(num // 2)

        return 1 + self.numberOfSteps(num - 1)
```

---

## Solution 3: Python – Bit Manipulation

**# Intuition**

We can calculate the total steps directly using the binary representation of the number.

The answer depends on the number of bits and the total number of set bits (1s).

**# Approach**

1. If `num == 0`, return 0.
2. `bit_length()` counts the number of bits.
3. `bit_count()` counts the number of set bits.
4. Subtract 1 from the bit length and add the set-bit count.

**# Complexity**

- Time complexity: O(log n)
- Space complexity: O(1)

**# Code**
```python
class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0

        return num.bit_length() - 1 + num.bit_count()
```

---

## Solution 4: C++ – Iterative (Normal Approach)

**# Intuition**

We repeatedly apply the given operations using a while loop. We divide even numbers by 2 and subtract 1 from odd numbers until the number becomes zero.

**# Approach**

1. Initialize `ans = 0`.
2. Run a while loop while `num > 0`.
3. If the number is even, divide it by 2.
4. Otherwise, subtract 1.
5. Increment the answer after each operation.
6. Return `ans`.

**# Complexity**

- Time complexity: O(log n)
- Space complexity: O(1)

**# Code**
```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;

        while(num > 0) {
            if(num % 2 == 0) {
                num /= 2;
            }
            else {
                num -= 1;
            }

            ans++;
        }

        return ans;
    }
};
```

---

## Solution 5: C++ – Recursion

**# Intuition**

We can solve the problem using recursion. Each function call performs one operation and adds 1 to the result of the next recursive call.

**# Approach**

1. If `num == 0`, return 0 (base case).
2. If the number is even, call the function with `num / 2`.
3. If the number is odd, call the function with `num - 1`.
4. Add 1 for every operation.
5. Return the final count.

**# Complexity**

- Time complexity: O(log n)
- Space complexity: O(log n), due to the recursion call stack.

**# Code**
```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0)
            return 0;

        if(num % 2 == 0)
            return 1 + numberOfSteps(num / 2);

        return 1 + numberOfSteps(num - 1);
    }
};
```

---

## Solution 6: C++ – Bit Manipulation

**# Intuition**

We can calculate the total steps directly from the binary representation. The number of steps depends on the bit length and the number of set bits.

**# Approach**

1. If `num == 0`, return 0.
2. `__builtin_clz()` counts the leading zeros in a 32-bit integer.
3. Subtract the leading zeros from 32 to get the bit length.
4. `__builtin_popcount()` counts the set bits (1s).
5. Subtract 1 from the bit length and add the set-bit count.

**# Complexity**

- Time complexity: O(1) for a fixed-width 32-bit integer.
- Space complexity: O(1)

**# Code**
```cpp
class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0)
            return 0;

        return (32 - __builtin_clz(num) - 1)
               + __builtin_popcount(num);
    }
};
```

---

## Comparison of All 6 Solutions

| Solution | Language | Approach | Auxiliary Space |
|---|---|---|---|
| 1 | Python | Iterative | O(1) |
| 2 | Python | Recursion | O(log n) |
| 3 | Python | Bit Manipulation | O(1) |
| 4 | C++ | Iterative | O(1) |
| 5 | C++ | Recursion | O(log n) |
| 6 | C++ | Bit Manipulation | O(1) |

**Important:** All six approaches produce the same answer. The iterative approach is straightforward, recursion demonstrates recursive problem-solving, and bit manipulation uses binary properties to calculate the result directly.

For C++ bit manipulation, `__builtin_clz()` and `__builtin_popcount()` are GCC/Clang built-ins. The given implementation assumes a 32-bit `int` and checks zero before calling `__builtin_clz()`.
