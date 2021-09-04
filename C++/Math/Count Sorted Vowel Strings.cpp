#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/count-sorted-vowel-strings/
 * </p>
 * For example, with n = 4 and we choose 4 numbers as 1 1 2 3,
 * there is always only 1 arrangement of 1123 to satisfy the requirements of the problem (ascending).
 * So the problem boils down to:
 *
 * @code Choose n elements from a set of 5 repeatable elements.
 * Also called iterative combination @endcode
 *
 *  Combination: C(n, k) = n! / ((n - k)! * k!)
 * <p></p>
 *  Iterative combination: C_(n,k) = C(n + k - 1, k)
 *                                 = (n + k - 1)! / ((n + k - 1 - k)! * k!)
 *                                 = (n + k - 1)! / ((n - 1)! * k!)
 * <p></p>
 *  With n = 5
 *  <p></p> So we have: C_(5,k) = (k+4)!/ (4! * k!)
 *                      = ((k + 1) * (k + 2) * (k + 3) * (k + 4)) / 24
 *  @param k is length of string
 *  @return Number of strings of length k that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
 * */

class Solution {
public:
    int countVowelStrings(int k) {
        return ((k + 1) * (k + 2) * (k + 3) * (k + 4)) / 24;
    }
};