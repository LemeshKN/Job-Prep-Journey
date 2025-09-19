/*
------------------------------------------------------------------------------------
Problem Statement:Add Strings
------------------------------------------------------------------------------------

Link: https://leetcode.com/problems/add-strings/

Description:
Given two non-negative integers, num1 and num2 represented as strings, return the 
sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large 
integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example:
Input: num1 = "123", num2 = "456"
Output: "579"

------------------------------------------------------------------------------------
My Approach: Manual Digit-by-Digit Addition
This solution simulates the process of elementary school addition, from right to left.

1.  Initialize two pointers, `i` and `j`, at the end of `num1` and `num2` respectively.
2.  Use a `while` loop that continues as long as there are digits to process in either
    string or there is a `carry` left over.
3.  Inside the loop, add the digit from `num1` (if `i` is valid), the digit from `num2`
    (if `j` is valid), and the `carry`.
4.  The new `carry` is the sum divided by 10, and the digit to append to our answer
    is the sum modulo 10.
5.  Since we are building the answer string from right to left (e.g., "975"), we must
    reverse it at the end to get the correct result ("579").

Time Complexity: O(max(N, M)), where N and M are the lengths of the two strings.
Space Complexity: O(max(N, M)), to store the resulting answer string.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        // Pointers for iterating from the end of the strings
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        std::string ans;

        // Loop until we've processed all digits and there's no carry left
        while (i >= 0 || j >= 0 || carry > 0) {
            int currentSum = 0;
            
            // Add digit from num1 if available
            if (i >= 0) {
                currentSum += num1[i] - '0'; // Convert char to int
                i--;
            }
            // Add digit from num2 if available
            if (j >= 0) {
                currentSum += num2[j] - '0'; // Convert char to int
                j--;
            }
            
            // Add the carry from the previous iteration
            currentSum += carry;
            
            // Calculate the last digit and the new carry
            int lastDigit = currentSum % 10;
            carry = currentSum / 10;
            
            // Append the last digit to the answer string
            ans.push_back(lastDigit + '0'); // Convert int back to char
        }
        
        // The answer is built in reverse, so we need to reverse it for the final result
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is the ideal and intended solution for this problem. It correctly simulates
manual addition and adheres to the constraint of not using built-in large integer
libraries. The logic is clean, efficient, and handles all edge cases like different
string lengths and the final carry. No further optimization is needed.
------------------------------------------------------------------------------------
*/