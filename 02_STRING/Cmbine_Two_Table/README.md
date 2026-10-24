# LeetCode 175 — Combine Two Tables

**Difficulty:** Easy  
**Language:** MySQL  
**Topic:** SQL JOINs, LEFT JOIN

## 1. Problem Statement

We are given two tables: `Person` and `Address`.

The `Person` table contains:
- `personId`: Unique ID of each person.
- `lastName`: Last name of the person.
- `firstName`: First name of the person.

The `Address` table contains:
- `addressId`: Unique ID of each address.
- `personId`: ID of the person associated with the address.
- `city`: City of the address.
- `state`: State of the address.

**Task:** Write a query to report each person's first name, last name, city, and state. If a person does not have an address in the `Address` table, return `NULL` for the city and state.

## 2. Intuition

The main idea is to combine the `Person` and `Address` tables using a `LEFT JOIN`.

We must include every person in the result, even if they do not have a corresponding address. An `INNER JOIN` would exclude people without matching addresses, so it would not satisfy the requirement.

A `LEFT JOIN` preserves all rows from the left table (`Person`) and adds matching information from the right table (`Address`). If no matching address exists, the address columns contain `NULL`.

## 3. Approach

1. Select `firstName` and `lastName` from the `Person` table.
2. Select `city` and `state` from the `Address` table.
3. Use `LEFT JOIN` to combine the two tables.
4. Match records using `personId` from both tables.
5. Return all people, including those without a matching address.

## 4. MySQL Solution

```sql
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person AS p
LEFT JOIN Address AS a
ON p.personId = a.personId;
```

## 5. Example

### Person Table

| personId | lastName | firstName |
|---:|---|---|
| 1 | Wang | Allen |
| 2 | Alice | Bob |

### Address Table

| addressId | personId | city | state |
|---:|---:|---|---|
| 1 | 2 | New York City | New York |
| 2 | 3 | Leetcode | California |

### Output

| firstName | lastName | city | state |
|---|---|---|---|
| Allen | Wang | NULL | NULL |
| Bob | Alice | New York City | New York |

**Note:** The sample illustrates the key concept: person 1 has no matching address, so their city and state are `NULL`. Person 3 does not appear because the query preserves rows from `Person`, not unmatched rows from `Address`.

## 6. Dry Run

### Step 1: Start with the Person table

There are two people:
- Allen Wang (`personId = 1`)
- Bob Alice (`personId = 2`)

### Step 2: Match records using personId

The join condition is:

```sql
ON p.personId = a.personId
```

- Person 1 has no matching address.
- Person 2 has an address in New York City, New York.

### Step 3: Apply LEFT JOIN

- Person 1 remains in the output, with `NULL` for city and state.
- Person 2 appears with the matching address details.

Therefore, both people appear in the result.

## 7. Why LEFT JOIN?

The question requires every person to appear, regardless of whether an address exists.

| JOIN Type | What it returns |
|---|---|
| INNER JOIN | Only rows with matching records in both tables |
| LEFT JOIN | All rows from the left table and matching rows from the right table |
| RIGHT JOIN | All rows from the right table and matching rows from the left table |
| FULL OUTER JOIN | All rows from both tables, including unmatched rows |

For this problem, `LEFT JOIN` is the correct choice because `Person` is the left table and every person must be included.

## 8. Complexity Analysis

**Time Complexity:** Depends on the execution plan, table sizes, and available indexes. A hash join can process the tables in expected `O(P + A)` time, where `P` is the number of rows in `Person` and `A` is the number of rows in `Address`.

**Space Complexity:** Depends on the execution plan. A hash join may require additional memory for its hash structure.

These are general complexity estimates, not guarantees for every MySQL execution plan.

## 9. Key Concepts to Remember

- `LEFT JOIN` preserves all rows from the left table.
- Matching rows are identified using the `ON` condition.
- If no matching right-side row exists, its selected columns return `NULL`.
- `INNER JOIN` would exclude people without addresses.
- Table aliases such as `p` and `a` make queries shorter and easier to read.
- The order of tables matters when choosing between `LEFT JOIN` and `RIGHT JOIN`.

## 10. Interview Revision

**Q1. Why did we use LEFT JOIN instead of INNER JOIN?**

Because every person must appear in the output, even if their address is missing.

**Q2. What happens when a person has no matching address?**

The person's name remains in the result, while `city` and `state` are `NULL`.

**Q3. What does the ON condition do?**

It specifies how rows from the two tables are matched.

**Q4. What would happen if we used INNER JOIN?**

People without matching addresses would be excluded.

**Q5. Does LEFT JOIN return unmatched rows from the right table?**

No. A LEFT JOIN preserves all rows from the left table. Unmatched right-side rows are not included.

## 11. One-Line Revision

**Use LEFT JOIN when you need every row from the left table, even when there is no matching row in the right table.**

## 12. Revision Practice

Try answering these questions without looking at the solution:

1. What is the difference between LEFT JOIN and INNER JOIN?
2. Why do city and state become NULL for some people?
3. What happens if you reverse the order of the tables and still use LEFT JOIN?
4. Which JOIN would you use if only people with addresses were required?
5. Write a query to display all people and their corresponding addresses.

**Status:** Solved  
**Revision:** Revisit the JOIN concept and solve the problem again without looking at the query.
