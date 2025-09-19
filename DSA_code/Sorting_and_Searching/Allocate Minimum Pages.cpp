/*
------------------------------------------------------------------------------------
Problem Statement:Allocate Minimum Pages
------------------------------------------------------------------------------------

Link: [https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1]

Description:
Given `n` books and `m` students, where `arr[i]` is the number of pages in the
i-th book. Allocate books to students such that the maximum number of pages
assigned to any student is minimized. Books must be assigned contiguously.

Example:
Input: arr = [12, 34, 67, 90], m = 2
Output: 113
Explanation: Allocation [12, 34, 67] to student 1 and [90] to student 2. The
maximum is 113.

------------------------------------------------------------------------------------
My Approach: Binary Search on the Answer Space
This is a classic problem that can be solved efficiently by applying binary search
on the space of possible answers. The answer (the minimum possible maximum pages)
must lie between the largest book size and the sum of all pages.

1.  Define the search space: `start = 0` (or max element), `end = sum of all pages`.
2.  Apply binary search. For each `mid` value, check if it's possible to allocate
    all books to `m` students such that no student reads more than `mid` pages.
3.  This check is done by a greedy helper function `isPossibleSolution`.
4.  If an allocation is possible with `mid`, it means `mid` is a potential answer. We
    store it and try for an even smaller maximum by searching the left half (`end = mid - 1`).
5.  If it's not possible, we need to allow students to read more pages, so we search
    the right half (`start = mid + 1`).

Time Complexity: O(n * log(sum of pages)).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    bool isPossibleSolution(int n, std::vector<int>& arr, int m, long long mid) {
        long long pageSum = 0;
        int studentCount = 1;
        
        for (int i = 0; i < n; i++) {
            // A single book cannot be larger than the max pages allowed (mid)
            if (arr[i] > mid) {
                return false;
            }
            // If adding the current book exceeds the limit, assign it to a new student
            if (pageSum + arr[i] > mid) {
                studentCount++;
                pageSum = arr[i];
                // If we've used more students than available, this solution is not possible
                if (studentCount > m) {
                    return false;
                }
            } else {
                // Otherwise, add the book to the current student's load
                pageSum += arr[i];
            }
        }
        return true;
    }

    long long findPages(int n, std::vector<int>& arr, int m) {
        if (m > n) return -1;

        long long s = 0;
        long long e = 0;
        for(int i=0; i<n; i++) e += arr[i];
        
        long long ans = -1;

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            if (isPossibleSolution(n, arr, m, mid)) {
                // This is a possible answer, try for an even better (smaller) one
                ans = mid;
                e = mid - 1;
            } else {
                // This is not possible, need to increase the page limit
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
This is an excellent application of the "Binary Search on Answer" pattern, which is
a crucial technique for solving many hard interview problems. The logic is sound,
and the greedy approach in the `isPossibleSolution` helper function is correct.
This solution is optimal and demonstrates a deep understanding of advanced
algorithmic patterns.
------------------------------------------------------------------------------------
*/