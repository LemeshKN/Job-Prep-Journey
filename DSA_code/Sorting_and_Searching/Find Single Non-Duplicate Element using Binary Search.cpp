/*
------------------------------------------------------------------------------------
Problem Statement: Find Single Non-Duplicate Element using Binary Search
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/single-element-in-a-sorted-array/description/]

Description:
You are given a sorted array where every element appears twice, except for one
element which appears once. Find this single non-duplicate element in O(log n) time.

Example:
Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
Output: 2

------------------------------------------------------------------------------------
My Approach: Binary Search based on Even/Odd Indices
The key observation is that in the sorted array, before the single element, all pairs
start at an even index (0, 2, 4, ...). After the single element, this pattern is
broken, and pairs start at an odd index. We can use this property in a binary search.

1.  In each step, find the `mid` index.
2.  We want to ensure `mid` always refers to the start of a pair, so if `mid` is odd,
    we decrement it to the previous even index.
3.  Now that `mid` is at an even index, we compare `nums[mid]` with `nums[mid+1]`.
4.  If they are the same, it means the pairs are still in order, and the single
    element must be in the right half. We set `start = mid + 2`.
5.  If they are different, it means the single element is in the left half (it could
    even be `nums[mid]`), so we shrink the search space by setting `end = mid`.
6.  The loop continues until `start` and `end` converge on the single element.

Time Complexity: O(log n).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        // The loop continues as long as there is more than one element in the range
        while (s < e) {
            int mid = s + (e - s) / 2;
            
            // Ensure mid is at the start of a potential pair (an even index)
            if (mid % 2 == 1) {
                mid--;
            }
            
            // If the pair is intact, the single element must be on the right side.
            // We can safely eliminate this pair and everything before it.
            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;
            } 
            // If the pair is broken, the single element is on the left side (including mid).
            else {
                e = mid;
            }
        }
        // When the loop ends, s and e will converge on the single element.
        return nums[s];
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
Your original logic was on the right track but a bit complex. The provided solution
above is a cleaner, standard binary search approach for this problem that relies on
a key insight about even/odd indices. Before the single element, `nums[2k] == nums[2k+1]`.
After the single element, this property is no longer true. The binary search
leverages this fact to discard half of the array in each step. This simplified
logic is more robust and easier to understand, which is highly valued in interviews.
------------------------------------------------------------------------------------
*/