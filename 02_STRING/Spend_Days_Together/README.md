# LeetCode 2409 — Count Days Spent Together

**Difficulty:** Easy  
**Language:** C++  
**Topics:** Arrays, Strings, Date Conversion, Math, Intervals

## 1. Problem Statement

Alice and Bob are traveling. We are given their arrival and departure dates in the format `MM-DD`.

- `arriveAlice`: Alice's arrival date.
- `leaveAlice`: Alice's departure date.
- `arriveBob`: Bob's arrival date.
- `leaveBob`: Bob's departure date.

We need to calculate the number of days Alice and Bob spend together.

Both the arrival date and departure date are inclusive.

**Goal:** Return the total number of days during which Alice and Bob are both present.

## 2. Intuition

The main idea is to find the overlapping period between Alice's and Bob's stays.

The common period starts on the later of their two arrival dates and ends on the earlier of their two departure dates.

To compare dates easily, we convert each date from `MM-DD` format into its corresponding day number in a non-leap year.

For example, August 15 becomes day 227 because 212 days occur before August and August 15 is the 15th day of August.

After converting the dates, we calculate:

- Common start day = maximum of the two arrival days.
- Common end day = minimum of the two departure days.

If the common end day is earlier than the common start day, there is no overlap, so we return `0`.

Otherwise, the number of common days is:

`end - start + 1`

We add `1` because both the starting and ending days are included.

## 3. Approach

1. Create an array containing the number of days in each month of a non-leap year.
2. Write a helper function `dayNumber()` that converts an `MM-DD` date into its day number.
3. Extract the month and day using `substr()` and convert them into integers using `stoi()`.
4. Add the days of all preceding months to the current day.
5. Convert Alice's arrival, Alice's departure, Bob's arrival, and Bob's departure dates into day numbers.
6. Find the common start day using `max(a1, b1)`.
7. Find the common end day using `min(a2, b2)`.
8. Return `max(0, end - start + 1)`.

## 4. C++ Solution

```cpp
class Solution {
public:
    int dayNumber(string date) {
        int days[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int a1 = dayNumber(arriveAlice);
        int a2 = dayNumber(leaveAlice);

        int b1 = dayNumber(arriveBob);
        int b2 = dayNumber(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        return max(0, end - start + 1);
    }
};
```

## 5. Example 1 — Overlapping Dates

### Input

```text
arriveAlice = "08-15"
leaveAlice  = "08-18"
arriveBob   = "08-16"
leaveBob    = "08-19"
```

### Timeline

```text
Date       Alice       Bob         Together?
08-15      Present     Absent      No
08-16      Present     Present     Yes
08-17      Present     Present     Yes
08-18      Present     Present     Yes
08-19      Absent      Present     No
```

### Output

```text
3
```

**Explanation:** Alice and Bob are both present on August 16, August 17, and August 18. Therefore, they spend 3 days together.

## 6. Dry Run

### Step 1: Convert dates into day numbers

The total number of days before August is:

31 + 28 + 31 + 30 + 31 + 30 + 31 = 212

Therefore:

| Date | Calculation | Day Number |
|---|---|---:|
| 08-15 | 212 + 15 | 227 |
| 08-18 | 212 + 18 | 230 |
| 08-16 | 212 + 16 | 228 |
| 08-19 | 212 + 19 | 231 |

We now have:

```cpp
a1 = 227;
a2 = 230;
b1 = 228;
b2 = 231;
```

### Step 2: Find the common start day

```cpp
int start = max(a1, b1);
```

Calculation:

```text
start = max(227, 228)
start = 228
```

The common period starts on August 16.

### Step 3: Find the common end day

```cpp
int end = min(a2, b2);
```

Calculation:

```text
end = min(230, 231)
end = 230
```

The common period ends on August 18.

### Step 4: Calculate the number of days

```cpp
return max(0, end - start + 1);
```

Calculation:

```text
= max(0, 230 - 228 + 1)
= max(0, 3)
= 3
```

**Final Answer: `3`**

## 7. Example 2 — No Overlapping Dates

### Input

```text
arriveAlice = "10-01"
leaveAlice  = "10-05"
arriveBob   = "10-06"
leaveBob    = "10-10"
```

### Calculation

Alice's stay ends on October 5, but Bob arrives on October 6.

Therefore, the common start is October 6, and the common end is October 5.

Since the end is earlier than the start, there is no overlap.

```text
end - start + 1 < 0
```

The result is:

```text
0
```

**Final Answer: `0`**

## 8. Important Concepts

### A. Converting a Date into a Day Number

The `dayNumber()` function converts an `MM-DD` string into an integer representing the day of the year.

For example:

```cpp
string date = "08-15";

int month = stoi(date.substr(0, 2));
int day = stoi(date.substr(3, 2));
```

Here:

- `date.substr(0, 2)` extracts `"08"`.
- `date.substr(3, 2)` extracts `"15"`.
- `stoi()` converts these strings into integers.

We then add the days in all preceding months.

### B. Why Use `month - 1`?

```cpp
for (int i = 0; i < month - 1; i++) {
    day += days[i];
}
```

The array uses zero-based indexing.

For August, `month = 8`, so we need to add the days in the first seven months.

The loop processes indices `0` through `6`, which correspond to January through July.

We do not add August's days again because the current day already represents the day within August.

### C. Why Use `max()` for the Start?

```cpp
int start = max(a1, b1);
```

The common period cannot start until both Alice and Bob have arrived.

Therefore, we choose the later arrival date.

### D. Why Use `min()` for the End?

```cpp
int end = min(a2, b2);
```

The common period ends as soon as either Alice or Bob leaves.

Therefore, we choose the earlier departure date.

### E. Why Add `1`?

```cpp
end - start + 1
```

Suppose the common period starts on day 10 and ends on day 12.

The days are:

```text
10, 11, 12
```

There are 3 days, not 2.

Therefore, we add `1` to include both endpoints.

### F. Why Use `max(0, ...)`?

```cpp
return max(0, end - start + 1);
```

When there is no overlap, the calculation can produce zero or a negative number.

We cannot have a negative number of days spent together, so we return at least zero.

## 9. Alternative Approach — Interval Overlap

This problem can also be solved directly using interval overlap.

Suppose the two date intervals are:

```text
Alice: [a1, a2]
Bob:   [b1, b2]
```

The overlap is:

```cpp
int start = max(a1, b1);
int end = min(a2, b2);
```

Then:

```cpp
if (start > end)
    return 0;

return end - start + 1;
```

This is the same interval-overlap logic used in scheduling, calendar applications, and meeting-time calculations.

**Important:** The dates must first be converted into comparable day numbers. Comparing raw `MM-DD` strings would not be a reliable general solution for this interval calculation.

## 10. Complexity Analysis

**Time Complexity: O(1)**

The helper function processes at most 11 preceding months for each date. Since the number of months is fixed, the work remains constant.

**Space Complexity: O(1)**

We use a fixed-size array of 12 integers and a constant number of variables. The additional space does not grow with the input size.

## 11. Common Mistakes

1. **Forgetting `+1`:** This causes an off-by-one error because both endpoints are inclusive.
2. **Using `min()` for the start:** The common start must be the later arrival date, so use `max()`.
3. **Using `max()` for the end:** The common end must be the earlier departure date, so use `min()`.
4. **Ignoring no-overlap cases:** If the common end is earlier than the common start, the answer must be zero.
5. **Adding the current month's days twice:** Add only the days of preceding months.
6. **Assuming every interval overlaps:** Alice and Bob can have completely separate stays.

## 12. Interview Questions and Answers

### Q1. What is the main idea behind this problem?

Convert the dates into day numbers and calculate the overlap between the two intervals.

### Q2. Why do we use `max(a1, b1)`?

Because the common period starts when the later-arriving person arrives.

### Q3. Why do we use `min(a2, b2)`?

Because the common period ends when the earlier-departing person leaves.

### Q4. Why do we add 1 to the result?

Both the first and last days of the overlapping period are included.

### Q5. What happens if Alice leaves before Bob arrives?

There is no overlap, so the answer is zero.

### Q6. Why is the time complexity O(1)?

The algorithm processes a fixed number of months and four dates, regardless of the year.

### Q7. What is an interval?

An interval is a range between a start point and an end point. Here, each person's stay is an interval of days.

### Q8. Where is interval-overlap logic useful?

It is useful in meeting scheduling, booking systems, calendar applications, reservation systems, and time-range comparisons.

## 13. One-Line Revision

**Convert the dates into day numbers, find the later arrival and earlier departure, and count the inclusive overlap using `max(0, end - start + 1)`.**

## 14. Revision Practice

Try solving these without looking at the solution.

### Question 1

```text
Alice: 05-10 to 05-15
Bob:   05-12 to 05-18
```

How many days do they spend together?

### Question 2

```text
Alice: 06-01 to 06-05
Bob:   06-05 to 06-10
```

Do they spend one day together or zero days together?

### Question 3

```text
Alice: 07-10 to 07-12
Bob:   07-13 to 07-15
```

What is the result when there is no overlap?

### Question 4

Explain in your own words why the formula is:

```cpp
max(0, end - start + 1)
```

## 15. Final Takeaway

This problem teaches three useful skills:

1. **Date conversion:** Transforming date strings into numerical values.
2. **Interval overlap:** Finding the common range between two intervals.
3. **Boundary handling:** Correctly counting inclusive endpoints and handling non-overlapping intervals.

Understanding these concepts will help you solve many other date-range and interval problems on LeetCode.

**Status:** Solved  
**Revision Goal:** Reimplement the solution without looking at the code and explain the `max()`, `min()`, and `+1` logic during an interview.
