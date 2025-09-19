/*
------------------------------------------------------------------------------------
Problem Statement:Remove All Occurrences of a Substring
------------------------------------------------------------------------------------

Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

Description:
Given two strings `s` and `part`, remove all occurrences of the substring `part` 
from `s`. You should continue to do so until `part` cannot be found in `s` anymore.

Return `s` after all such removals have been made.

Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

------------------------------------------------------------------------------------
My Approach: Find-and-Erase Loop
This solution uses built-in string functions to repeatedly find and remove the
substring `part`.

1.  Use a `while` loop that continues as long as an occurrence of `part` can be
    found within `s`. The `string::find()` method is perfect for this.
2.  Inside the loop, `string::find()` returns the starting index of the first
    occurrence of `part`.
3.  The `string::erase()` method is then used to remove the substring, using the
    found index and the length of `part`.
4.  The loop repeats until `find()` no longer locates the substring, at which point
    the modified string is returned.

Time Complexity: O(n * m), where n is the length of `s` and m is the length of `part`.
Space Complexity: O(1) (if `erase` is considered in-place).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        // Continue looping as long as the substring `part` is found in `s`
        // string::npos is a constant representing a non-position, returned when a substring is not found.
        while (s.find(part) != std::string::npos) {
            // Erase the first occurrence of `part` found.
            // s.find(part) gives the starting index.
            // part.length() gives the number of characters to remove.
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This solution is very clean, readable, and correctly solves the problem. For many
scenarios, this is a great answer.

It's good to be aware that the time complexity of repeatedly using `find` and `erase`
can be high, as each operation can take linear time.

A more time-efficient approach for very large strings would be to build the result
string in a single pass using a "stack-like" method:
1.  Iterate through the input string `s`, character by character, appending each
    character to a new `result` string.
2.  After appending each character, check if the end of the `result` string now
    matches `part`.
3.  If it does, pop those characters off the end of `result`.
This single-pass method generally achieves a better time complexity of O(n * m).
------------------------------------------------------------------------------------
*/