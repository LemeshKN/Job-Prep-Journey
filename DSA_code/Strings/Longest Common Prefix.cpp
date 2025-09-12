/*
------------------------------------------------------------------------------------
Problem Statement: Longest Common Prefix
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/longest-common-prefix/description/]

Description:
Given an array of strings `strs`, find the longest common prefix string amongst
all strings in the array. If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower", "flow", "flight"]
Output: "fl"

------------------------------------------------------------------------------------
My Approach: Vertical Scanning
This solution finds the longest common prefix by scanning vertically, character by
character, across all the strings.

1.  Use an outer `while(true)` loop that iterates through the character indices
    (i = 0, 1, 2, ...).
2.  For each index `i`, an inner loop iterates through all the strings in the array.
3.  It takes the character at index `i` from the first string (`strs[0][i]`) as a
    reference.
4.  It then checks if this character matches the character at the same index `i` for
    all other strings.
5.  If a mismatch is found, or if any string is shorter than the current index `i`,
    the loop breaks, and the common prefix found so far is returned.
6.  If all strings match at index `i`, the character is added to the answer, and the
    outer loop continues to the next index.

Time Complexity: O(S), where S is the sum of all characters in all strings.
Space Complexity: O(min_len), where min_len is the length of the shortest string (for the answer).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        std::string ans;
        int i = 0;
        
        while (true) {
            char curr_ch = 0;
            // Iterate through each string in the input vector
            for (int j = 0; j < strs.size(); j++) {
                // If we've gone past the end of the current string, stop.
                if (i >= strs[j].size()) {
                    curr_ch = 0;
                    break;
                }
                
                // If this is the first string, set its character as the one to match.
                if (curr_ch == 0) {
                    curr_ch = strs[j][i];
                }
                // If the character in another string doesn't match, stop.
                else if (curr_ch != strs[j][i]) {
                    curr_ch = 0;
                    break;
                }
            }
            
            // If at any point curr_ch is reset to 0, it means we found the end of the prefix.
            if (curr_ch == 0) {
                break;
            }
            
            // If all strings matched, add the character to our answer and check the next index.
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
The vertical scanning approach is a very solid and often highly efficient method.
It's particularly fast when the common prefix is short.

Another popular and elegant approach involves sorting:
1.  Sort the input array of strings alphabetically (e.g., ["flower", "flow", "flight"]