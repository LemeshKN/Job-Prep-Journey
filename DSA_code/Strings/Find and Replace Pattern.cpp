/*
------------------------------------------------------------------------------------
Problem Statement:Find and Replace Pattern
------------------------------------------------------------------------------------

Link: https://leetcode.com/problems/find-and-replace-pattern/

Description:
Given a list of strings `words` and a string `pattern`, return a list of `words`
that match the `pattern`. A word matches the pattern if there exists a permutation
of letters such that every letter in `pattern` is mapped to a unique letter in the
word.

Example:
Input: words = ["abc", "deq", "mee", "aqq", "dkd", "ccc"], pattern = "abb"
Output: ["mee", "aqq"]

------------------------------------------------------------------------------------
My Approach: String Normalization
This clever approach determines if a word matches a pattern by converting both
the word and the pattern into a "normalized" or "canonical" form.

1.  A helper function `normalizeString` takes a string and creates a mapping for each
    unique character. It replaces each character with a standard, sequential
    character (e.g., 'a', then 'b', etc.). For example, "mee" becomes "abb" and "aqq"
    also becomes "abb".
2.  First, normalize the input `pattern` string once.
3.  Then, iterate through each `word` in the `words` list.
4.  For each `word`, create a temporary copy and normalize it.
5.  If the normalized word is identical to the normalized pattern, the original word
    is a match and is added to the answer list.

Time Complexity: O(N * K), where N is the number of words and K is the length of each word.
Space Complexity: O(K), for the hash map used in normalization for each word.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // Helper function to convert a string to its canonical pattern
    void normalizeString(std::string& str) {
        char start = 'a';
        std::unordered_map<char, char> mapping;

        // Iterate through the string to build and apply the mapping
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            // If we've never seen this character before, map it to the next available char
            if (mapping.find(ch) == mapping.end()) {
                mapping[ch] = start;
                start++;
            }
            // Replace the character with its mapped equivalent
            str[i] = mapping[ch];
        }
    }
    
    std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
        std::vector<std::string> ans;
        
        // First, normalize the pattern itself to its canonical form
        normalizeString(pattern);
        
        // Iterate through each word in the input list
        for (int i = 0; i < words.size(); i++) {
            std::string currentWord = words[i]; // Create a copy to modify
            
            // Normalize the current word
            normalizeString(currentWord);
            
            // If the normalized word matches the normalized pattern, it's a valid match
            if (pattern == currentWord) {
                ans.push_back(words[i]); // Add the original word to the answer
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
The string normalization approach is a highly elegant and efficient way to solve this
problem. It correctly identifies the core of the problem, which is about matching
patterns, not specific characters. Your `normalizeString` helper function can be
slightly optimized by combining the two loops into one, but the overall logic and
time complexity remain the same. This is an excellent and insightful solution.
------------------------------------------------------------------------------------
*/