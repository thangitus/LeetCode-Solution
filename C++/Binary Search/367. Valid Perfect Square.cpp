
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (mid * mid == num)return true;

            if (mid * mid < num)
                low = (int) mid + 1;
            else high = (int) mid - 1;
        }
        return false;
    }
};
