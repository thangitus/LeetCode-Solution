#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/repeated-dna-sequences/
 * */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_map<string, int> map;
        vector<string> result;
        for (int i = 0; i < s.length() - 10; i++) {
            string sequence = s.substr(i, 10);
            map[sequence]++;
            if (map[sequence] == 2) result.push_back(sequence);
        }
        return result;
    }
};
