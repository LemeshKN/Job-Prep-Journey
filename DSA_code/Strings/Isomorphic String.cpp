/*
------------------------------------------------------------------------------------
Problem Statement: Isomorphic String
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/isomorphic-strings/description/]

Description:
Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced 
to get `t`, maintaining the order of characters. No two characters may map to the
same character, but a character may map to itself.

Example 1:
Input: s = "paper", t = "title"
Output: true

Example 2:
Input: s = "ab", t = "aa"
Output: false

------------------------------------------------------------------------------------
My Approach: String Normalization
This is a clever approach that determines if two strings are isomorphic by
converting them both into a "normalized" or "canonical" pattern.

1.  A helper function `normalizeString` takes a string and creates a mapping for each
    unique character it encounters for the first time.
2.  It replaces each character in the string with its mapped character (e.g., 'e' maps
    to 'a', 'g' maps to 'b', so "egg" becomes "abb").
3.  The main function `isIsomorphic` creates copies of both input strings, normalizes
    both of them using the helper function.
4.  If the two normalized strings are identical, it means they follow the exact same
    character pattern, and therefore they are isomorphic.

Time Complexity: O(n), where n is the length of the strings.
Space Complexity: O(k), where k is the number of unique characters in the strings (for the map).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Helper function to convert a string to its canonical form
    void normalizeString(std::string& str) {
        char start = 'a';
        std::unordered_map<char, char> mapping;
        
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            // If we've never seen this character before, create a new mapping for it
            if (mapping.find(ch) == mapping.end()) {
                mapping[ch] = start;
                start++;
            }
            // Replace the original character with its mapped character
            str[i] = mapping[ch];
        }
    }
    
    bool isIsomorphic(const std::string& s, const std::string& t) {
        if (s.length() != t.length()) return false;
        
        // Create mutable copies of the input strings
        std::string s1 = s;
        std::string t1 = t;
        
        // Normalize both strings
        normalizeString(s1);
        normalizeString(t1);
        
        // If their normalized forms are the same, they are isomorphic.
        return s1 == t1;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
The string normalization approach is an elegant and insightful way to solve this
problem. It correctly captures the essence of what it means for two strings to have
the same pattern. The code is clean and the logic is sound. This is an excellent
and efficient solution. No further optimization is needed.
------------------------------------------------------------------------------------
*/