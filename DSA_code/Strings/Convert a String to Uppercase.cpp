/*
------------------------------------------------------------------------------------
Problem Statement: Convert a String to Uppercase
------------------------------------------------------------------------------------

Link: https://www.geeksforgeeks.org/conversion-of-string-to-uppercase-in-cpp/

Description:
Create a function that transforms all lowercase letters in a given string to their
corresponding uppercase counterparts. The function should only process ASCII
characters.

Example:
Input: s = "Hello, World!"
Output: "HELLO, WORLD!"

------------------------------------------------------------------------------------
My Approach: In-place ASCII Conversion
This solution iterates through the string and modifies the characters in-place.

1.  Use a `while` loop or a `for` loop to visit each character of the string.
2.  For each character, check if it falls within the ASCII range of lowercase
    letters ('a' to 'z').
3.  If it is a lowercase letter, convert it to uppercase. This is done by
    subtracting the ASCII value of 'a' and adding the ASCII value of 'A'. This
    simple arithmetic correctly shifts the character to its uppercase equivalent.
4.  The function modifies the original string directly.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as the modification is done in-place.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string toUpperCase(std::string s) {
        // Iterate through each character of the string
        for (int i = 0; i < s.size(); i++) {
            // Check if the character is a lowercase letter
            if (s[i] >= 'a' && s[i] <= 'z') {
                // Convert to uppercase using ASCII arithmetic
                s[i] = s[i] - 'a' + 'A';
            }
        }
        return s;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is the perfect, standard, and most efficient way to solve this problem. It
correctly modifies the string in-place with O(1) extra space and linear time.
The use of ASCII arithmetic is a key skill to demonstrate. No further optimization
is needed.
------------------------------------------------------------------------------------
*/