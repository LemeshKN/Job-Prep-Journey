/*
------------------------------------------------------------------------------------
Problem Statement: Reorganize String
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/reorganize-string/description/]

Description:
Given a string `s`, rearrange its characters such that no two adjacent characters
are the same. If it's impossible, return an empty string "".

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

------------------------------------------------------------------------------------
My Approach: Greedy with Frequency Count
This is a greedy approach that places the most frequent character first, ensuring
it is spread out as much as possible.

1.  Count the frequency of each character in the string using a hash map (or an array
    since characters are limited).
2.  Find the most frequent character and its count.
3.  Check if a valid rearrangement is possible. If any character appears more than
    (n+1)/2 times, it's impossible to separate them, so return "".
4.  Place the most frequent character at all the even indices (0, 2, 4, ...).
5.  Iterate through the frequency map again and place all the remaining characters
    in the remaining available slots (continuing with even indices if any are left,
    then starting from odd indices 1, 3, 5, ...).

Time Complexity: O(n), as we iterate through the string and the character map a constant number of times.
Space Complexity: O(1), as the character map has a fixed size (26 for lowercase English letters).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reorganizeString(const std::string& s) {
        // Use a simple array as a hash map for character frequencies
        int map[256] = {0};
        for (char ch : s) {
            map[ch]++;
        }

        // Find the most frequent character
        char most_freq_char = ' ';
        int max_freq = 0;
        for (int i = 0; i < 256; i++) {
            if (map[i] > max_freq) {
                max_freq = map[i];
                most_freq_char = (char)i;
            }
        }
        
        // Check if a solution is possible
        if (max_freq > (s.size() + 1) / 2) {
            return "";
        }
        
        std::string ans = s;
        int index = 0;
        
        // Place the most frequent character at even indices
        while (map[most_freq_char] > 0) {
            ans[index] = most_freq_char;
            map[most_freq_char]--;
            index += 2;
        }

        // Place the rest of the characters
        for (int i = 0; i < 256; i++) {
            while (map[i] > 0) {
                // If we've run out of even indices, start at the first odd index
                if (index >= ans.size()) {
                    index = 1;
                }
                ans[index] = (char)i;
                map[i]--;
                index += 2;
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This greedy approach is a very clever and efficient way to solve the Reorganize
String problem. The logic of placing the most frequent character first at spaced
intervals is the key insight, and you have implemented it well. The check for
impossibility (`max_freq > (n+1)/2`) is also correct and crucial. This is a
high-quality, optimal solution.
------------------------------------------------------------------------------------
*/