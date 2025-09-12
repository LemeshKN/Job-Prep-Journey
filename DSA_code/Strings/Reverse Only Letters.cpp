/*
------------------------------------------------------------------------------------
Problem Statement: Reverse Only Letters
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/reverse-only-letters/description/]

Description:
Given a string `s`, reverse only the alphabetical letters in the string while 
keeping all non-alphabetical characters in their original positions.

Example:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

------------------------------------------------------------------------------------
My Approach: Two-Pointer Technique
This solution uses the efficient two-pointer technique to reverse the letters in-place.

1.  Initialize two pointers: `i` at the beginning of the string and `j` at the end.
2.  Create a copy of the string to modify, as the input is constant.
3.  Use a `while` loop that continues as long as `i` is less than or equal to `j`.
4.  Inside the loop:
    - If the character at `i` is not a letter, move `i` forward.
    - If the character at `j` is not a letter, move `j` backward.
    - If both characters at `i` and `j` are letters, swap them, and then move both
      pointers inward.
5.  This process continues until the pointers cross, resulting in all letters
    being reversed while non-letters remain untouched.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(n), because a copy of the string is created to perform the swaps.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    // Helper function to check if a character is an alphabet
    bool isAlphabet(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    std::string reverseOnlyLetters(const std::string& s) {
        int i = 0;
        int j = s.size() - 1;
        std::string result = s; // Make a mutable copy

        while (i <= j) {
            if (isAlphabet(result[i]) && isAlphabet(result[j])) {
                // Both are letters, so swap them
                std::swap(result[i], result[j]);
                i++;
                j--;
            } else if (!isAlphabet(result[i])) {
                // Left is not a letter, skip it
                i++;
            } else {
                // Right is not a letter, skip it
                j--;
            }
        }
        return result;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is the ideal and most efficient solution for this problem. The two-pointer 
approach is a classic pattern for in-place modifications and you have implemented it
perfectly. The use of a helper function `isAlphabet` also makes the code clean and
readable. No further optimization is needed.
------------------------------------------------------------------------------------
*/