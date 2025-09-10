/*
------------------------------------------------------------------------------------
Problem Statement:Find Quotient Without Using Division and Modulus Operators
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/divide-two-integers/description/]

Description:
Given two integers, `dividend` and `divisor`, compute the quotient without using
division (/) or modulus (%). The result should be truncated towards zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

------------------------------------------------------------------------------------
My Approach: Binary Search on the Answer Space
This problem can be framed as "Find the largest number `q` such that `divisor * q <= dividend`."
This monotonic property allows us to use binary search on the space of possible quotients.

1.  Handle edge cases like `divisor = 0`.
2.  Work with absolute values of the dividend and divisor to simplify the logic.
3.  The search space for the quotient is from `s = 0` to `e = dividend`.
4.  In each step, calculate a `mid` quotient. If `divisor * mid <= dividend`, then `mid` is
    a possible answer, so we store it and try for a larger quotient by searching the
    right half (`s = mid + 1`).
5.  If `divisor * mid > dividend`, the `mid` is too large, so we search the left half.
6.  Finally, determine the correct sign of the result based on the original signs.

Time Complexity: O(log(dividend)).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cmath>
#include <limits.h>

class Solution {
public:
    long long int solve(long long int dividend, long long int divisor) {
        long long int s = 0;
        long long int e = dividend;
        long long int ans = -1;

        while (s <= e) {
            long long int mid = s + ((e - s) >> 1); // Using right shift for division by 2
            long long product = divisor * mid;
            
            if (product == dividend) {
                return mid;
            } else if (product > dividend) {
                // Mid is too large
                e = mid - 1;
            } else {
                // Mid is a potential answer, store it and try for a larger one
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }

    long long int findQuotient(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        // Use long long for absolute values to handle INT_MIN correctly
        long long abs_dividend = std::abs((long long)dividend);
        long long abs_divisor = std::abs((long long)divisor);
        
        long long int ans = solve(abs_dividend, abs_divisor);
        
        // Determine the sign of the final answer
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return ans;
        } else {
            return (0 - ans);
        }
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is an excellent and non-trivial solution. Using binary search on the answer
space is a powerful technique that you've applied correctly. The implementation is
robust, with good handling of signs and the crucial division-by-zero edge case.
The use of `long long int` is also very important here to prevent overflow,
especially when dealing with `abs(INT_MIN)`. A more advanced optimization involves
using exponential search with bit manipulation, but this binary search approach is
a very strong and impressive solution for an interview.
------------------------------------------------------------------------------------
*/