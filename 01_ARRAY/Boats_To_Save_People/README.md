# LeetCode 881 — Boats to Save People

## Intuition

We need to minimize the number of boats.

Each boat can carry at most two people, and their combined weight must not exceed the given `limit`.

After sorting the array:

* `left` points to the lightest person.
* `right` points to the heaviest person.

We always try to put the heaviest person with the lightest person.

Why?

If the heaviest person cannot fit with the lightest person, then they cannot fit with anyone else either because everyone else is heavier than the lightest person.

Therefore, the heaviest person must go alone.

This greedy strategy gives the minimum number of boats.

## Approach

1. Sort the `people` array.
2. Initialize:

   * `left = 0`
   * `right = people.size() - 1`
   * `boatCount = 0`
3. While `left <= right`:

   * Check whether the lightest and heaviest people can share a boat.
   * If `people[left] + people[right] <= limit`:

     * Put both in the same boat.
     * Move both pointers.
   * Otherwise:

     * The heaviest person must go alone.
     * Move only `right`.
   * Increment `boatCount`.
4. Return `boatCount`.

## Example

Input:

```text
people = [3, 2, 2, 1]
limit = 3
```

After sorting:

```text
[1, 2, 2, 3]
```

* `1 + 3 = 4` → exceeds limit → `3` goes alone.
* `1 + 2 = 3` → both go together.
* Remaining `2` → goes alone.

Total:

```text
3 boats
```

## Complexity

### Time Complexity

```text
O(n log n)
```

Sorting takes `O(n log n)` and the two-pointer traversal takes `O(n)`.

Overall:

```text
O(n log n)
```

### Space Complexity

```text
O(1)
```

Apart from the sorting implementation's internal space.

## C++ Solution

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCount = 0;

        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;

        while (left <= right) {

            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            }
            else {
                right--;
            }

            boatCount++;
        }

        return boatCount;
    }
};
```

## Pattern

**Sorting + Two Pointers + Greedy**

This is an important pattern for problems where we need to pair the smallest and largest elements while satisfying a constraint.
