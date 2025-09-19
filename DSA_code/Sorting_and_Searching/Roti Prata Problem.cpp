/*
------------------------------------------------------------------------------------
Problem Statement:Roti Prata Problem
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/koko-eating-bananas/description/]

Description:
Given `p` pratas and `l` cooks with different ranks `R`. A cook with rank `R` takes
`R` minutes for the 1st prata, `2R` for the 2nd, `3R` for the 3rd, and so on.
Find the minimum time required to cook all `p` pratas.

Example 1:
Input: p = 10, l = 4, ranks = [1, 2, 3, 4]
Output: 12

------------------------------------------------------------------------------------
My Approach: Binary Search on the Answer Space (Time)
This is another problem that can be solved by applying binary search on the answer,
where the answer is the minimum possible time to cook all pratas.

1.  The search space for time is from `s = 0` to a sufficiently large upper bound.
2.  For each `mid` time value, a helper function `isPossibleSolution` checks if it's
    possible for all cooks to make at least `p` pratas combined within `mid` minutes.
3.  The helper function iterates through each cook. For a given cook and `mid` time,
    it calculates how many pratas they can make. It sums the pratas from all cooks.
4.  If the total pratas are >= `p`, then `mid` is a possible time, so we store it and
    try for an even smaller time by searching the left half (`e = mid - 1`).
5.  If not, we need more time, so we search the right half (`s = mid + 1`).

Time Complexity: O(l * sqrt(time) * log(time)), where `l` is the number of cooks.
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // Checks if it's possible to make 'p' pratas within 'mid' minutes.
    bool isPossibleSolution(const std::vector<int>& ranks, int p, int mid) {
        int currentP = 0; // Pratas cooked so far

        // For each cook, find out how many pratas they can make in 'mid' time
        for (int rank : ranks) {
            int timeElapsed = 0;
            int prataCount = 1;
            while (true) {
                if (timeElapsed + prataCount * rank <= mid) {
                    timeElapsed += prataCount * rank;
                    currentP++;
                    prataCount++;
                } else {
                    break;
                }
            }
            if (currentP >= p) {
                return true;
            }
        }
        return false;
    }

    int minTimeToCookPratas(int p, const std::vector<int>& ranks) {
        int l = ranks.size();
        // A safe upper bound for time can be calculated, but a large number also works
        // for competitive programming.
        int s = 0;
        int e = ranks[0] * (p * (p + 1) / 2); // Upper bound based on the fastest cook
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossibleSolution(ranks, p, mid)) {
                // This time is possible, try for a better (smaller) time
                ans = mid;
                e = mid - 1;
            } else {
                // Not possible to cook all pratas, need more time
                s = mid + 1;
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is another great example of recognizing and applying the "Binary Search on
Answer" pattern to a complex problem. The logic is solid. A small optimization
can be made in the `isPossibleSolution` function. Instead of the `while(true)` loop
to calculate the number of pratas a cook can make, one could use a mathematical
formula derived from the quadratic equation for the sum of an arithmetic series.
However, for interview purposes, the implemented looping approach is clear, correct,
and demonstrates the core algorithmic skill effectively.
------------------------------------------------------------------------------------
*/