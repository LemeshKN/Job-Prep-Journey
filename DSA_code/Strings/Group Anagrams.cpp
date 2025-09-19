/*
------------------------------------------------------------------------------------
Problem Statement: Group Anagrams
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/group-anagrams/description/]

Description:
Given an array of strings `strs`, group the anagrams together. An anagram is a word
formed by rearranging the letters of another, using all original letters exactly once.

Example:
Input: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

------------------------------------------------------------------------------------
My Approach: Hash Map with Sorted Key
This is the classic and most elegant solution for grouping anagrams. The core idea is
that all anagrams, when their letters are sorted alphabetically, will result in the
exact same string.

1.  Create a hash map (`std::unordered_map`) where the key is a string and the value
    is a vector of strings.
2.  Iterate through the input array of strings.
3.  For each string, create a sorted version of it. This sorted string will serve as
    the unique key for its anagram group.
4.  Use this key to store the original string in the hash map. All anagrams will
    naturally be pushed into the same vector in the map.
5.  Finally, iterate through the map and collect all the value vectors to form the
    final result.

Time Complexity: O(N * K log K), where N is the number of strings and K is the maximum length of a string.
Space Complexity: O(N * K), to store the hash map and the result.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        // The map will hold the sorted string as a key and a list of its anagrams as the value
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        // Iterate through each string in the input
        for (const std::string& s : strs) {
            // Create a sorted version of the string to use as the key
            std::string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            // Add the original string to the list for its corresponding sorted key
            anagramGroups[sortedStr].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        // Iterate through the map and collect the grouped anagrams
        for (auto const& [key, val] : anagramGroups) {
            result.push_back(val);
        }
        
        return result;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This solution is perfect. Using a sorted version of the string as a key in a hash
map is the standard, most intuitive, and highly efficient way to group anagrams.
The code is clean, easy to understand, and correctly implemented. This is an
interview-ready, optimal solution.
------------------------------------------------------------------------------------
*/