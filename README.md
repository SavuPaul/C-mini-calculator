# Arithmetic Expression Evaluation Program

This program evaluates arithmetic expressions by processing two main vectors:
- **`term`**: a vector of real numbers, where each position holds an operand.
- **`op`**: a vector of characters, where each position represents an operation to be performed.

## Table of Contents
1. [Task 1: Sequential Operations](#task-1-sequential-operations)
2. [Task 2: Priority Operations](#task-2-priority-operations)
3. [Task 3: Multiple Priority Levels](#task-3-multiple-priority-levels)

---

### Task 1: Sequential Operations

In Task 1, operations are performed sequentially, with each operation modifying the value of the `result` variable as it is calculated. This straightforward evaluation involves iterating through the `op` vector and applying each operation directly to the elements in `term`.

### Task 2: Priority Operations

Task 2 introduces operator precedence, specifically giving higher priority to the `*` and `/` operations. This priority is managed using the `prio` variable, which tracks the number of remaining high-priority operations.

1. **Priority Execution**: Whenever a high-priority operation is encountered, it is performed first, and `prio` is decremented by one.
2. **Vector Shifting**: Both vectors (`term` and `op`) shift left by one position after each operation is executed. This effectively removes the completed operation from `op` and the right-hand operand from `term`, while the left-hand operand is replaced by the result of the evaluated expression.
3. **Non-priority Execution**: Once there are no more high-priority operations, the vector is processed from the start to handle the remaining operations sequentially, as in Task 1.

#### Index Correspondence

The corresponding operation between elements `term[i]` and `term[i+1]` is located at position `i+1` in the `op` vector.

### Task 3: Multiple Priority Levels

Task 3 builds upon the algorithm in Task 2, adding a new priority level for the `#` operator. The `prio_mid` variable is introduced to manage this intermediate priority, functioning similarly to `prio` from Task 2.

1. **Intermediate Priority Execution**: When there are no more first-priority operations (`*` and `/`), the `term` vector is revisited to handle `#` operations using the `prio_mid` variable.
2. **Lowest Priority Execution**: After completing `#` operations, the vector is revisited again to perform `+` and `-` operations sequentially, following the same approach as in Task 1.

This structure ensures that all operations are executed in the correct order of precedence, from highest to lowest.

--- 
This program efficiently evaluates complex arithmetic expressions by maintaining structured precedence and sequential operations.

