/*
------------------------------------------------------------------------------------
Problem Statement: Find Square Root using Binary Search
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/sqrtx/description/]

Description:
Given a non-negative integer `x`, compute and return the integer part of its 
square root. The calculation should be done using binary search.

Example 1:
Input: x = 16
Output: 4

------------------------------------------------------------------------------------
My Approach: Binary Search on the Answer
The integer square root of `x` must be a number between 0 and `x`. This creates a
sorted search space of possible answers, which is perfect for binary search.

1.  Set the search space from `start = 0` to `end = x`.
2.  In each step, calculate `mid` and its square (`mid * mid`).
3.  If `mid*mid == x`, we've found the perfect square root.
4.  If `mid*mid < x`, then `mid` could be our answer, so we store it. However, a larger
    number might also be a valid, larger integer root, so we search the right half
    by setting `start = mid + 1`.
5.  If `mid*mid > x`, `mid` is too large, so we search the left half by setting `end = mid - 1`.
6.  Using `long long` for `mid` and the product prevents integer overflow for large `x`.

Time Complexity: O(log x).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long long s = 1;
        long long e = x;
        long long ans = -1;

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long product = mid * mid;

            if (product == x) {
                // Perfect square found
                return mid;
            } 
            if (product < x) {
                // This mid is a potential answer, store it and look for a larger one
                ans = mid;
                s = mid + 1;
            } else {
                // The square is too big, search in the left half
                e = mid - 1;
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is an excellent and robust solution. Using binary search on the answer space is
the optimal approach. A particularly important detail is the use of `long long int`
for the `mid` and `product` variables. This correctly prevents potential integer
overflow when `mid*mid` exceeds the capacity of a standard `int`, which is a
critical edge case that shows strong attention to detail.
------------------------------------------------------------------------------------
*/