/*
------------------------------------------------------------------------------------
Problem Statement: String to Integer (atoi)
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/string-to-integer-atoi/description/]

Description:
Implement a function `myAtoi(string s)` that converts a string to a 32-bit signed
integer, similar to the C/C++ `atoi` function. The function must handle leading
whitespace, optional signs (+/-), non-digit characters, and integer overflow.

Example:
Input: "   -42"
Output: -42

------------------------------------------------------------------------------------
My Approach: Step-by-Step Parsing
This solution carefully simulates the required parsing logic step by step.

1.  Initialize variables: `result` (as a `long` to prevent overflow during
    calculation), `i` (for the string index), and `sign`.
2.  **Whitespace:** Skip any leading whitespace characters.
3.  **Sign:** Check for an optional '+' or '-' sign and set the `sign` variable
    accordingly.
4.  **Digits:** Iterate through the subsequent characters as long as they are digits.
    In each step, build the number by multiplying the current result by 10 and adding
    the new digit.
5.  **Overflow Check:** Inside the digit loop, continuously check if the `result`
    multiplied by the `sign` has exceeded the 32-bit integer limits (`INT_MAX` or
    `INT_MIN`). If it has, clamp the value to the limit and return immediately.
6.  **Final Result:** Return the final `result` multiplied by the `sign`.

Time Complexity: O(n), where n is the length of the string, as we do a single pass.
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits> // Required for INT_MAX and INT_MIN

class Solution {
public:
    int myAtoi(const std::string& s) {
        long result = 0; // Use long to detect overflow before it happens
        int i = 0;
        int sign = 1; // Assume positive sign by default

        // 1. Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        
        // 2. Check for optional sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Read digits and build the number
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0'); // Convert char to int and add to result

            // 4. Check for overflow on each addition
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            
            i++;
        }

        // 5. Apply the sign and cast to int for the final result
        return (int)(sign * result);
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is a robust and high-quality solution for the `atoi` problem. The step-by-step
parsing logic is clear and correctly handles all the specified edge cases like
whitespace, signs, and non-digit characters. The use of a `long` variable to build
the result and check for overflow before it happens is a standard and effective
technique. This is an excellent, interview-ready implementation.
------------------------------------------------------------------------------------
*/