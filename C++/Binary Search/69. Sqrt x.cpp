
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x / 2 + 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if ((long long) mid * mid > x)
                right = mid - 1;
            else left = mid + 1;
        }
        return (long long) mid * mid > x ? mid - 1 : mid;
    }
};
