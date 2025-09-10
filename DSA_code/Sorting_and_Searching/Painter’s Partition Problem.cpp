/*
------------------------------------------------------------------------------------
Problem Statement:Painter’s Partition Problem
------------------------------------------------------------------------------------
Link[https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1]

Description:
Given an array `boards` where `boards[i]` is the length of the i-th board and `k`
painters. Find the minimum time to paint all boards, where each painter can only
paint contiguous boards and takes 1 unit of time per unit of length. This is
equivalent to minimizing the maximum board length assigned to any single painter.

Example:
Input: boards = [10, 20, 30, 40], k = 2
Output: 60

------------------------------------------------------------------------------------
My Approach: Binary Search on the Answer Space
This problem is a classic variation of the "Allocate Minimum Pages" problem. The
logic is identical. We can apply binary search on the space of possible answers, where
the answer is the minimum possible time (which corresponds to the max board length
for any painter).

1.  The search space for time is from `start = 0` to `end = sum of all board lengths`.
2.  For each `mid` time value, a greedy helper function checks if it's possible to
    assign all boards to `k` painters such that no painter works for more than `mid` time.
3.  If it's possible, `mid` is a potential answer, and we search for a smaller time.
4.  If not, we must allow more time, so we search the right half.

Time Complexity: O(n * log(sum of board lengths)).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    bool isPossibleSolution(std::vector<int>& boards, int k, int mid) {
        long long timeSum = 0;
        int painterCount = 1;
        for (int i = 0; i < boards.size(); i++) {
            if (boards[i] > mid) {
                return false;
            }
            if (timeSum + boards[i] > mid) {
                painterCount++;
                timeSum = boards[i];
                if (painterCount > k) {
                    return false;
                }
            } else {
                timeSum += boards[i];
            }
        }
        return true;
    }

    int minTime(std::vector<int>& boards, int k) {
        long long s = 0;
        long long e = 0;
        for (int i = 0; i < boards.size(); i++) {
            e += boards[i];
        }
        long long ans = -1;

        while (s <= e) {
            long long mid = s + (e-s) / 2;
            if (isPossibleSolution(boards, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
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
This is a perfect implementation. The key insight is recognizing that this problem
is structurally identical to the "Allocate Minimum Pages" problem, which you have
done. Applying the same "Binary Search on Answer" pattern here shows a strong
ability to identify and apply known algorithmic templates to new problems. The
solution is optimal and well-executed.
------------------------------------------------------------------------------------
*/