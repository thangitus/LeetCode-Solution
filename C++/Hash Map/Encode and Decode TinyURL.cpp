#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/encode-and-decode-tinyurl/
class Solution {
private:
    map<string, string> map;
public:

    string encode(string longUrl) {
        string res = to_string(rand() % 10000000);
        res += to_string(time(0));
        map[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

