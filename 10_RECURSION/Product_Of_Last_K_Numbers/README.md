# Intuition
We need to design a data structure that supports two operations:
- `add(num)`: Add a number to the stream.
- `getProduct(k)`: Return the product of the last `k` numbers.

Instead of multiplying the last `k` elements every time, we can use the Prefix Product technique to calculate the result in O(1) time.

# Approach
1. Initialize a prefix array with `1`.
2. In the `add()` method:
   - If the number is `0`, reset the prefix array to `[1]` because division by zero is not possible.
   - Otherwise, multiply the new number with the previous prefix product and append the result.
3. In the `getProduct()` method:
   - If `k` is greater than or equal to the prefix array size, return `0` because a zero exists among the last `k` numbers.
   - Otherwise, divide the last prefix product by the prefix product before the last `k` elements.
4. This allows us to calculate the product without traversing the last `k` elements.

# Complexity
- **Time Complexity:**
  - `add()` → O(1) amortized
  - `getProduct(k)` → O(1)
- **Space Complexity:** O(n), where n is the number of non-zero elements added since the last zero.

# Code

## Python 3
```python
class ProductOfNumbers:

    def __init__(self):
        self.prefix = [1]

    def add(self, num: int) -> None:

        if num == 0:
            self.prefix = [1]

        else:
            self.prefix.append(self.prefix[-1] * num)

    def getProduct(self, k: int) -> int:

        if k >= len(self.prefix):
            return 0

        return self.prefix[-1] // self.prefix[-k-1]


# C++
```
C++ Solution - optimal 
```cpp
class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {

        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {

        if (k >= prefix.size()) {
            return 0;
        }

        return prefix.back() / prefix[prefix.size() - k - 1];
    }
};
```
