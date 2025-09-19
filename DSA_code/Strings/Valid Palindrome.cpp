/*
------------------------------------------------------------------------------------
Problem Statement:Valid Palindrome
------------------------------------------------------------------------------------

Link: https://leetcode.com/problems/valid-palindrome/

Description:
A phrase is a palindrome if, after converting all uppercase letters into lowercase 
letters and removing all non-alphanumeric characters, it reads the same forward 
and backward.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

------------------------------------------------------------------------------------
My Approach: Filter and Then Check
This solution first cleans the string and then checks if the cleaned version is a palindrome.

1.  Create a new, empty string `ans`.
2.  Iterate through the original string `s`.
3.  For each character, check if it is an alphabet or a digit.
4.  If it is, convert it to lowercase and append it to the `ans` string.
5.  After the first pass, `ans` contains the filtered, lowercase version of the string.
6.  Use a standard two-pointer approach on the `ans` string to check if it's a
    palindrome.

Time Complexity: O(n), for iterating through the string twice.
Space Complexity: O(n), for creating the new `ans` string.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string ans;
        // Step 1: Filter the string and convert to lowercase
        for (int i = 0; i < s.size(); i++) {
            // Check for lowercase letters and digits
            if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ) {
                ans.push_back(s[i]);
            }
            // Check for uppercase letters and convert them
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                ans.push_back(tolower(s[i]));
            }
        }
        
        // Step 2: Check if the cleaned string is a palindrome using two pointers
        int i = 0;
        int j = ans.size() - 1;
        while (i <= j) {
            if (ans[i] != ans[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is a correct and easy-to-understand solution. For many interviews, this would
be a perfectly acceptable answer.

To make it even better, you could solve it with O(1) extra space. The current
solution uses O(n) space because of the new `ans` string.

The O(1) Space Approach (Two Pointers on the Original String):
1.  Use two pointers, `left` at the start and `right` at the end of the original string `s`.
2.  In a `while` loop, move the `left` pointer forward until it finds an alphanumeric character.
3.  Similarly, move the `right` pointer backward until it finds an alphanumeric character.
4.  Once both pointers are on alphanumeric characters, compare them (after converting to
    lowercase). If they don't match, return `false`.
5.  If they match, move both pointers inward (`left++`, `right--`) and continue.

This in-place method is more memory-efficient and is a great alternative to know.
------------------------------------------------------------------------------------
*/